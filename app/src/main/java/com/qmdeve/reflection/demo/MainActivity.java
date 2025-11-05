package com.qmdeve.reflection.demo;

import android.os.Bundle;
import android.util.Log;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

import java.lang.reflect.Method;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        findViewById(R.id.test).setOnClickListener(v -> reflectionTest());
    }

    public void reflectionTest() {
        try {
            Class<?> activityClass = Class.forName("dalvik.system.VMRuntime");
            Method field = activityClass.getDeclaredMethod("setHiddenApiExemptions", String[].class);
            field.setAccessible(true);
            Log.d("QmReflectionLib", "Success");
        } catch (Throwable e) {
            Log.d("QmReflectionLib", "Error: ", e);
        }
    }
}