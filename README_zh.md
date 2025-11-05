<div align="center">

## QmReflection
**QmReflection 是一个专为 Android 开发的轻量级库，用于绕过 Android 9.0 (API 28) 及以上设备对反射使用的限制**

<br>
<br>

  <img src="https://img.shields.io/badge/License-Apache%202.0-blue.svg" alt="Apache"/>
  <img src="https://img.shields.io/badge/targetSdk-36-green" alt="targetSdk"/>
  <img src="https://img.shields.io/maven-central/v/com.qmdeve/QmReflection" alt="maven"/>
  <img src="https://img.shields.io/github/stars/QmDeve/QmReflection" alt="Stars"/>

<br>
<br>

[English](https://github.com/QmDeve/QmReflection/blob/master/README.md) | 简体中文

<br>

[QQ 交流群](https://qm.qq.com/q/46EanJ9nN6)

</div>

---

## 特性
 - **支持 `Android P (API 28)` 及以上设备**
 - **轻量级，无额外依赖**
 - **初始化仅需一行代码**

---

## 快速集成
[![Maven Central](https://img.shields.io/maven-central/v/com.qmdeve/QmReflection)](https://central.sonatype.com/artifact/com.qmdeve/QmReflection)
### **添加依赖项**
```gradle
dependencies {
    implementation 'com.qmdeve:QmReflection:1.0.0'
}
```

---

## 使用方法
### 在 `Application` 或 `Activity` 的 `attachBaseContext` 方法中初始化：
```java
@Override
public void attachBaseContext(Context base) {
    super.attachBaseContext(base);
    QmReflection.initialize(base);
}
```

### 基础使用
**初始化后，你可以正常使用反射而不会受到系统限制**

#### 示例代码
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

### 兼容性
 - **Android 9.0 (API 28) 及以上设备**

---

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=QmDeve/QmReflection&type=date&legend=bottom-right)](https://www.star-history.com/#QmDeve/QmReflection&type=date&legend=bottom-right)

---

### 我的其他开源库
- **[QmBlurView](https://github.com/QmDeve/QmBlurView)**
- **[AndroidLiquidGlassView](https://github.com/QmDeve/AndroidLiquidGlassView)**

---

### 赞助我们

**如果您觉得我们的项目对您有帮助，欢迎通过以下方式赞助支持：**

![赞助二维码](https://youke1.picui.cn/s1/2025/11/04/6909d2ae165f0.png)