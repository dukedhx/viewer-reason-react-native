
import React from "react";
import { SafeAreaView, StatusBar, Text, Platform } from "react-native";
import StaticServer from "react-native-static-server";
import {make as AppComponent} from './src/App.bs.js';
import RNFS from "react-native-fs";

export default class extends React.Component {
  state = {
    url: null
  }
  async componentDidMount() {
    if (Platform.OS == "android") {
      await RNFS.mkdir(RNFS.DocumentDirectoryPath + "/www");
      const files = ["www/index.html"];
      await files.forEach(async file => {
        await RNFS.copyFileAssets(file, RNFS.DocumentDirectoryPath + "/" + file);
      })
    }
    this.server = new StaticServer(8080, Platform.OS == "android" ? RNFS.DocumentDirectoryPath + "/www":RNFS.MainBundlePath + "/www");
    this.server.start().then(url =>this.setState({ url }))
  }

  componentWillUnmount() {
    if (this.server && this.server.isRunning()) {
      this.server.stop();
    }
  }

  render() {
    if (!this.state.url) {
      return (
        <SafeAreaView>
          <Text>Loading</Text>
        </SafeAreaView>
      );
    }
    return (
      <>
        <StatusBar barStyle="dark-content" />
        <AppComponent url={this.state.url} />
      </>
    );
  }
}
