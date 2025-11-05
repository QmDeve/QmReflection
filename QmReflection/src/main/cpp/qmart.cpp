#include <jni.h>
#include "qmart.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/system_properties.h>

template<typename T>
int findOffset(void *start, int regionStart, int regionEnd, T value) {
    if (nullptr == start || regionEnd <= 0 || regionStart < 0) {
        return -1;
    }

    char *c_start = reinterpret_cast<char*>(start);
    for (int i = regionStart; i < regionEnd; i += 4) {
        T *current_value = reinterpret_cast<T*>(c_start + i);
        if (value == *current_value) {
            return i;
        }
    }
    return -2;
}

template<typename Runtime>
int applyBypass(Runtime *partialRuntime) {
    partialRuntime->hidden_api_policy_ = EnforcementPolicy::kNoChecks;
    return 0;
}

int bypassReflectionRestrictions(JNIEnv *env, jint targetSdkVersion) {
    char api_level_str[5] = {0};
    char preview_api_str[5] = {0};

    if (__system_property_get("ro.build.version.sdk", api_level_str) == 0) {
        return -1;
    }

    __system_property_get("ro.build.version.preview_sdk", preview_api_str);

    int api_level = atoi(api_level_str);
    bool is_preview = atoi(preview_api_str) > 0;
    bool isAndroidR = api_level >= 30 || (api_level == 29 && is_preview);

    JavaVM *javaVM;
    if (env->GetJavaVM(&javaVM) != JNI_OK) {
        return -1;
    }

    auto *javaVMExt = reinterpret_cast<JavaVMExt*>(javaVM);
    void *runtime = javaVMExt->runtime;

    const int MAX_SEARCH_RANGE = 2000;
    int offsetOfVmExt = findOffset(runtime, 0, MAX_SEARCH_RANGE,
                                   reinterpret_cast<size_t>(javaVMExt));

    if (offsetOfVmExt < 0) {
        return -2;
    }

    int startOffset = isAndroidR ? offsetOfVmExt + 200 : offsetOfVmExt;

    int targetSdkVersionOffset = findOffset(runtime, startOffset, MAX_SEARCH_RANGE,
                                            static_cast<int32_t>(targetSdkVersion));

    if (targetSdkVersionOffset < 0) {
        return -3;
    }

    if (isAndroidR) {
        auto *partialRuntime = reinterpret_cast<PartialRuntimeR*>(
                reinterpret_cast<char*>(runtime) + targetSdkVersionOffset);
        return applyBypass<PartialRuntimeR>(partialRuntime);
    } else {
        auto *partialRuntime = reinterpret_cast<PartialRuntime*>(
                reinterpret_cast<char*>(runtime) + targetSdkVersionOffset);
        return applyBypass<PartialRuntime>(partialRuntime);
    }
}

extern "C" JNIEXPORT jint JNICALL
Java_com_qmdeve_reflection_QmReflection_bypassReflectionRestrictionsNative(
        JNIEnv *env, jclass type, jint targetSdkVersion) {
    return bypassReflectionRestrictions(env, targetSdkVersion);
}