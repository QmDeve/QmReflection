#ifndef FREEREFLECTION_QMART_H
#define FREEREFLECTION_QMART_H

#include <jni.h>
#include <string>
#include <cstdint>

struct JavaVMExt {
    void *functions;
    void *runtime;
};

enum class EnforcementPolicy {
    kNoChecks = 0,
    kJustWarn = 1,
    kDarkGreyAndBlackList = 2,
    kBlacklistOnly = 3,
    kMax = 3,
};

struct PartialRuntime {
    int32_t target_sdk_version_;
    bool implicit_null_checks_;
    bool implicit_so_checks_;
    bool implicit_suspend_checks_;
    bool no_sig_chain_;
    bool force_native_bridge_;
    bool is_native_bridge_loaded_;
    bool is_native_debuggable_;
    bool is_java_debuggable_;
    std::string fingerprint_;
    bool safe_mode_;
    EnforcementPolicy hidden_api_policy_;
};

struct PartialRuntimeR {
    uint32_t target_sdk_version_;
    void *disabled_compat_changes_[3];
    bool implicit_null_checks_;
    bool implicit_so_checks_;
    bool implicit_suspend_checks_;
    bool no_sig_chain_;
    bool force_native_bridge_;
    bool is_native_bridge_loaded_;
    bool is_native_debuggable_;
    bool is_java_debuggable_;
    std::string fingerprint_;
    bool safe_mode_;
    EnforcementPolicy hidden_api_policy_;
};

int bypassReflectionRestrictions(JNIEnv *env, jint targetSdkVersion);

#endif