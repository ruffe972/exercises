import React from 'react';
import './App.css';

class App extends React.Component {
  render() {
    return (
      <div className="App">
        Change me
        <br></br>
        <button onClick={this.temp}>
          Click me
        </button>
      </div>
    );
  }

  // constructor(props) {
  //   super(props);
  // }

  temp(): void {
    fetchJson('/hello', console.log);
  }
}

function fetchJson(input: String, successCallback: (value: unknown) => void) {
  fetch('http://localhost:8080' + input)
    .then(response => response.json())
    .then(successCallback)
    .catch(() => alert('Request error'));
}

export default App;
