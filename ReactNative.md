App entry boilerplate code

```javascript
import React from 'react';
import { AppRegistry } from 'react-native';
import Main from './src/components/Main';

// Create a component
const App = () => (
  <Main />
);

// Render it to the device
AppRegistry.registerComponent('albums', () => App);
```
