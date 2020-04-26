import React, { useEffect } from 'react';
import './App.css';
import { useSelector, useDispatch } from 'react-redux';
import { AppState, incrementCreator, decrementCreator } from './store/store';
import { useArticles } from './hooks/devto';

function App() {
  useEffect(() => {
    // Update the document title using the browser API
    document.title = `You clicked ${count} times`;
  });
  const count = useSelector((state: AppState) => {
    return state.count;
  });
  const { articles, loading, error } = useArticles();
  const dispatch = useDispatch();
  return (
    <>
      <div>Your count is {count}</div>
      <button onClick={() => dispatch(incrementCreator())}>+</button>
      <button onClick={() => dispatch(decrementCreator())}>-</button>
      {loading ? <div>loading...</div> : undefined}
      {error ? <div>error!!</div> : undefined}
      {articles.length > 0 ? (
        <ul>
          {articles.map((a, i) => {
            return <li key={i}>{a.title}</li>;
          })}
        </ul>
      ) : undefined}
      }
    </>
  );
}

export default App;
