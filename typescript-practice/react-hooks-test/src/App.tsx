import React, { useState } from 'react';
import './App.css';
import { useSelector, useDispatch } from 'react-redux';
import { AppState, incrementCreator, decrementCreator } from './store/store';

function App() {
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
