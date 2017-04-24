import * as React from 'react';
import * as ReactDOM from 'react-dom';
import { connect, ComponentDecorator, Provider } from 'react-redux';
import { createStore, Store } from 'redux';

// Action
const Increment: string = 'INCREMENT';
const Decrement: string = 'DECREMENT';

// # Action Createor
// ## Increment
interface IIncrementAction {
  type: string;
  value: number;
}

function increment(value: number): IIncrementAction {
  return { type: Increment, value: value };
}

// ## Decrement
interface IDecrementAction {
  type: string;
  value: number;
}

function decrement(value: number): IDecrementAction {
  return { type: Decrement, value: value };
}

// # Reducer
// ## State
interface IState {
  value: number;
}

// ## Action type definition
type Action = IIncrementAction | IDecrementAction;

// ## Reducer
function Reducer(state: IState, action: Action): IState { switch (action.type) { case 'INCREMENT':
      return Object.assign({}, state, { value: state.value + action.value});
    case 'DECREMENT':
      return Object.assign({}, state, { value: state.value - action.value});
    default:
      return state;
  }
}

// ## initialState
const initialState: IState = {
  value: 1
};

// # Store
const store: Store<IState> = createStore(Reducer, initialState);

// ----------- Index ------------------
// ## IProps
interface IIndexProps {
  onIncrement: Function;
  onDecrement: Function;
  value: number;
};

class Index extends React.Component<IIndexProps, IState> {
  constructor(props: IIndexProps) {
    super(props);
  };
  render(): JSX.Element {
    return (
      <div>
        <NumberDisplay value={this.props.value} />
        <IncrementButton onIncrement={this.props.onIncrement} />
        <DecrementButton onDecrement={this.props.onDecrement} />
      </div>
    );
  }
}
// Interfaces for component
// class Index extends React.Component <any, any> {
// Number Display
interface INumberDisplayProps extends React.Props<any> {
  value: number;
}

class NumberDisplay extends React.Component<INumberDisplayProps, any> {
  constructor(props: INumberDisplayProps) {
    super(props);
  }
  render(): JSX.Element {
    return (
      <div>
        {this.props.value}
      </div>
    );
  }
}

// Increment Button
interface IIncrementButtonProps {
  onIncrement: Function;
};

class IncrementButton extends React.Component<IIncrementButtonProps, void> {
  constructor() {
    super();
  }
  onClick(): void {
    this.props.onIncrement(1);
  }
  render(): JSX.Element {
    return (
      <div>
        <button onClick={this.onClick.bind(this)}>+</button>
      </div>
    );
  }
}

// Decrement Button
interface IDecrementButton {
  onDecrement: Function;
}

class DecrementButton extends React.Component<IDecrementButton, void> {
  constructor() {
    super();
  }
  onClick(): void {
    this.props.onDecrement(1);
  }
  render(): JSX.Element {
    return (
      <div>
        <button onClick={this.onClick.bind(this)}>-</button>
      </div>
    );
  }
}

// ------------ MapToProps ------------------
function mapStateToProps(state: IState): any {
  return { value: state.value };
}

// ------------ MapDispatchToProps------------------
function MapDispatchToProps(dispatch: any): any {
  return {
    onIncrement(value: number): void {
      dispatch(increment(value));
    },
    onDecrement(value: number): void {
      dispatch(decrement(value));
    }
  };
}

// Container
const AppContainer: any = connect(
  mapStateToProps,
  MapDispatchToProps
)(Index);

// Provider
ReactDOM.render(
  <Provider store={store}>
    <AppContainer />
  </Provider>,
  document.querySelector('#content')
);
