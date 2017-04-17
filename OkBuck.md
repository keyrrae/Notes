In root project build.gradle file:
```gradle
buildscript {
    repositories {
        jcenter()
    }
    dependencies {
        classpath 'com.uber:okbuck:0.20.4'
    }
}

repositories {
    jcenter()
}

apply plugin: 'com.uber.okbuck'
```
In app's build.gradle
```gradle
android {
    ...
    signingConfigs {
        release {
            storeFile file('../debug.keystore')
            storePassword 'android'
            keyAlias 'androiddebugkey'
            keyPassword 'android'
        }
    }
    buildTypes {
        debug {
            signingConfig signingConfigs.release
        }
        release {
            signingConfig signingConfigs.release
        }
    }
    ...
}
```

Run the buck wrapper task

```
./gradlew :buckWrapper
```
