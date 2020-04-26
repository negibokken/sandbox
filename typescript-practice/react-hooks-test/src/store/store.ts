import { createStore, Action } from 'redux';

export enum Types {
  INCREMENT = 'INCREMENT',
  DECREMENT = 'DECREMENT',
}

export interface AppState {
  count: number;
}

export const incrementCreator = () => {
  return { type: Types.INCREMENT };
};

export const decrementCreator = () => {
  return { type: Types.DECREMENT };
};

const initialState: AppState = {
  count: 0,
};

const reducer = (state = initialState, action: Action) => {
  switch (action.type) {
    case Types.INCREMENT: {
      return { ...state, ...{ count: state.count + 1 } };
    }
    case Types.DECREMENT: {
      return { ...state, ...{ count: state.count - 1 } };
    }
    default: {
      return state;
    }
  }
};

export const store = createStore(reducer);
