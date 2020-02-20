[![Build Status](https://travis-ci.org/dukedhx/viewer-reason-react-native.svg?branch=master)](https://travis-ci.org/dukedhx/viewer-reason-react-native)
[![License](http://img.shields.io/:license-mit-blue.svg)](http://opensource.org/licenses/MIT)
[![Autodesk Forge](https://img.shields.io/badge/Autodesk-Forge-orange.svg)](https://forge.autodesk.com/)
[![Reason React](https://img.shields.io/badge/Reason-React-Native-blue.svg)](https://reason-react-native.github.io/)
[![Platform](https://img.shields.io/badge/Platform-iOS|Android-green.svg)](https://forge.autodesk.com/)

# Description

Autodesk Forge Viewer React Native sample with Reason React component to load SVF locally.

Original post: https://forge.autodesk.com/blog/build-cross-platform-viewer-apps-reason-react-native-and-nativescript-angular

# Why Reason React Reason (ReasonML)?

Reason React Native is a safe & simple way to build React Native apps, using ReasonReact - a safer, simpler way to build React components, in Reason.

But is Reason a new language and why bother to learn it? - it's not! Reason is a new syntax and toolchain powered by the battle-tested language, OCaml. Reason gives OCaml a familiar syntax geared toward JavaScript programmers, and caters to the existing NPM/Yarn workflow folks already know. In that regard, Reason can be considered as a solidly, statically typed, faster and simpler cousin of JavaScript, minus the historical crufts, plus the features of ES2030 you can use today, and with access to both the JS and the OCaml ecosystem!

So by leveraging the ReasonML great type system, expressive language features and smooth interoperability with JavaScript (thanks to BuckleScript), Reason React Native provide bindings for React Native features as components & APIs that are:

- Safe and statically typed with a rock solid type system, but w/o all the hassle of TypeScript (still true of 3.x at least) when developers have often got to wrestle with common pitfalls like type anonymity and null assertions.
- Lighting fast and great interop - Reason can be compiled to JavaScript using the build system, bsb, which finishes incremental builds in less than 100ms with resulting output also tiny.
- Simple and lean, with a focus on simplicity & pragmatism. Reason allows opt-in side-effect, mutation and objects for familiarity & interop, while keeping the rest of the language pure, immutable and functional.
- Great ecosystem & tooling. Use your favorite editor, your favorite NPM package, and any of your favorite existing stack
- Familiar and easy to insert into an existing React Native codebase, exactly like what we are doing with our code sample - adding a Reason component of WebView with Viewer in it to an existing React Native app.

Talk is cheap so let's get to the code! Let's simply take any of your existing React Native project and add Reason React Native as dependencies, which is quite straightforward so see instructions here: https://reason-react-native.github.io/en/docs/install/

# Project Structure

```
|-- ./App.js      // React Native component
|-- ./index.js    // App entry
|-- ./src/app.re  // Reason React component
|-- ./www         // HTMLs and Model SVFs
```

# Setup and Run

## Prerequisites
- Node.JS (install [here](https://nodejs.org/en/download/))
- Reason React Native: https://reason-react-native.github.io/

## Build and Run

- Clone this project
- Copy your model's SVF files to `www` and edit the load path accordingly in `www/index.html` (or feel free to change the code to load from remote URL or Forge services if preferred)
- `npm install` // install Node.js dependencies
- `npx react-native upgrade --legacy true` // Eject the project to generate platform specific emits, remove '--legacy true' if error
- `npm run re:build`  // Build ReasonML to JS

### iOS

- Copy HTMLs and model SVFs to "/www" which is where the static server looks for resources by default 
- Open the project in "./ios" on Xcode (best to open the workspace: `ios/<ProjectName>.xcworkspace`)
- Add the "./www" folder to the project
- `npm run ios`

### Android

- Copy HTMLs and model SVFs to "/www" which is where the static server looks for resources by default 
- Add the below to your `app/build.gradle`:
```
// app/build.gradle
android {
...
    sourceSets { main { assets.srcDirs = ['src/main/assets', '../../assets'] } }
}
```
- `npm run android`

# License

[MIT](http://opensource.org/licenses/MIT)

# Written By

[Bryan Huang](https://www.linkedin.com/in/bryan-huang-1447b862) - Forge Partner Development https://forge.autodesk.com
