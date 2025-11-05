package com.qmdeve.reflection;

import android.content.Context;
import android.text.TextUtils;
import android.util.Base64;
import android.util.Log;

import java.io.File;
import java.io.FileOutputStream;
import java.lang.reflect.Method;

import dalvik.system.DexFile;

import static android.os.Build.VERSION.SDK_INT;

public class QmReflection {
    static {
        try {
            System.loadLibrary("QmReflection");
        } catch (Exception e) {
            Log.e("QmReflectionLib", "Error: ", e);
        }
    }
    private static final String ENCODED_DEX = "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";
    private static native int bypassReflectionRestrictionsNative(int target);

    public static void initialize(Context context) {
        if (SDK_INT < 28) return;
        if (bypassViaDexFile(context)) return;
        bypassReflectionRestrictionsNative(context.getApplicationInfo().targetSdkVersion);
    }

    private static boolean bypassViaDexFile(Context context) {
        byte[] dexBytes = Base64.decode(ENCODED_DEX, Base64.NO_WRAP);
        File cacheDir = getCacheDirectory(context);

        if (cacheDir == null) return false;

        File dexFile = new File(cacheDir, "QmReflection_" + System.currentTimeMillis() + ".dex");
        boolean success = false;

        try {
            try (FileOutputStream outputStream = new FileOutputStream(dexFile)) {
                outputStream.write(dexBytes);
            }

            setFileReadOnly(dexFile);

            DexFile loadedDex = new DexFile(dexFile);
            Class<?> bootstrapClass = loadedDex.loadClass("com.qmdeve.reflection.Bsc", null);
            Method exemptAllMethod = bootstrapClass.getDeclaredMethod("exemptAll");
            Boolean result = (Boolean) exemptAllMethod.invoke(null);
            success = Boolean.TRUE.equals(result);
        } catch (Exception e) {
            Log.e("QmReflectionLib", "Error: ", e);
        } finally {
            cleanupTempFile(dexFile);
        }
        return success;
    }

    private static File getCacheDirectory(Context context) {
        if (context != null) {
            return context.getCodeCacheDir();
        }

        String tempDir = System.getProperty("java.io.tmpdir");
        if (TextUtils.isEmpty(tempDir)) {
            return null;
        }

        File tempDirectory = new File(tempDir);
        return tempDirectory.exists() ? tempDirectory : null;
    }

    private static void setFileReadOnly(File file) {
        try {
            boolean success = file.setReadOnly();
            if (!success) {
                Log.w("QmReflectionLib", "Failed to set file as read-only: " + file.getAbsolutePath());
            }
        } catch (SecurityException e) {
            Log.w("QmReflectionLib", "Security exception setting file read-only", e);
        }
    }

    private static void cleanupTempFile(File file) {
        if (file != null && file.exists()) {
            boolean deleted = file.delete();
            if (!deleted) {
                Log.w("QmReflectionLib", "Failed to delete temporary file: " + file.getAbsolutePath());
            }
        }
    }
}