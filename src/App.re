open ReactNative;
type reactNativeNewAppScreenColors = {
  .
  "primary": string,
  "white": string,
  "lighter": string,
  "light": string,
  "black": string,
  "dark": string,
};

[@bs.module "react-native/Libraries/NewAppScreen"]
external colors: reactNativeNewAppScreenColors = "Colors";



module WebView ={
  module Source = {
    type t;

    [@bs.obj]
    external uri:
      (
        ~uri: string=?,
        ~method: string=?,
        ~headers: Js.t('a)=?,
        ~body: string=?,
        unit
      ) =>
      t =
      "";
  };
[@react.component][@bs.module "react-native-webview"]
external make: (~source: Source.t=?) => React.element = "default";
}

let styles =
  Style.(
    StyleSheet.create({
      "body": style(~backgroundColor=colors##white,~flex=11., ()),
      "header": style(~backgroundColor=colors##primary,~flex=1., ()),
      "headerText": style(
          ~color=colors##white,
          ~fontSize=18.,
          ~fontWeight=`_600,
          ~paddingTop=35.->dp,
          ~textAlign=`center,()),
    }),
  );

[@react.component]
let make = (~url) =>
  <>
        <View style={styles##header}> <Text style={styles##headerText}> "Autodesk Forge"->React.string </Text></View>
        <View style={styles##body}>
        <WebView
          source=WebView.Source.uri(~uri=url, ())
          />
        </View>
  </>;
