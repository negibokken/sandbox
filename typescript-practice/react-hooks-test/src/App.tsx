import React, { useEffect } from 'react';
import './App.css';
import { useSelector, useDispatch } from 'react-redux';
import { AppState, incrementCreator, decrementCreator } from './store/store';

function App() {
  useEffect(() => {
    // Update the document title using the browser API
    document.title = `You clicked ${count} times`;
  });
  const count = useSelector((state: AppState) => {
    return state.count;
  });
  const dispatch = useDispatch();
  return (
    <>
      <div>Your count is {count}</div>
      <button onClick={() => dispatch(incrementCreator())}>+</button>
      <button onClick={() => dispatch(decrementCreator())}>-</button>
    </>
  );
}

export default App;
