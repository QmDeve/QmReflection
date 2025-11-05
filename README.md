<div align="center">

## QmReflection
**QmReflection is a lightweight library specially developed for Android to bypass the restrictions on the use of reflection on Android 9.0 (API 28) and above devices**

<br>
<br>

  <img src="https://img.shields.io/badge/License-Apache%202.0-blue.svg" alt="Apache"/>
  <img src="https://img.shields.io/badge/targetSdk-36-green" alt="targetSdk"/>
  <img src="https://img.shields.io/maven-central/v/com.qmdeve/QmReflection" alt="maven"/>
  <img src="https://img.shields.io/github/stars/QmDeve/QmReflection" alt="Stars"/>

<br>
<br>

English | [简体中文](https://github.com/QmDeve/QmReflection/blob/master/README_zh.md)

<br>

[Telegram Group](https://t.me/QmDeves)

</div>

---

## Characteristic
- **Supports `Android 9.0 (API 28)` and above devices**
- **Lightweight, no additional dependencies**
- **Only one line of code is needed for initialization**

---

## Quick integration
[![Maven Central](https://img.shields.io/maven-central/v/com.qmdeve/QmReflection)](https://central.sonatype.com/artifact/com.qmdeve/QmReflection)
### **Add dependencies**
```gradle
dependencies {
    implementation 'com.qmdeve:QmReflection:1.0.0'
}
```

---

## How to use
### Initialize in the `attachBaseContext` method of `Application` or `Activity`:
```java
@Override
public void attachBaseContext(Context base) {
    super.attachBaseContext(base);
    QmReflection.initialize(base);
}
```

### Basic usage
**After initialization, you can use reflection normally without being restricted by the system.**

#### Sample code
```java
try {
    Class<?> activityClass = Class.forName("dalvik.system.VMRuntime");
    Method field = activityClass.getDeclaredMethod("setHiddenApiExemptions", String[].class);
    field.setAccessible(true);
    Log.d("QmReflectionLib", "Success");
} catch (Throwable e) {
    Log.d("QmReflectionLib", "Error: ", e);
}
```

---

### Compatibility
- **Android 9.0 (API 28) and above devices**

---

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=QmDeve/QmReflection&type=date&legend=bottom-right)](https://www.star-history.com/#QmDeve/QmReflection&type=date&legend=bottom-right)

---

### My other open-source library
- **[QmBlurView](https://github.com/QmDeve/QmBlurView)**
- **[AndroidLiquidGlassView](https://github.com/QmDeve/AndroidLiquidGlassView)**