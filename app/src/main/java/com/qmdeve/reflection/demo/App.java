package com.qmdeve.reflection.demo;

import android.app.Application;
import android.content.Context;

import com.qmdeve.reflection.QmReflection;

public class App extends Application {
    @Override
    public void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        QmReflection.initialize(base);
    }
}
