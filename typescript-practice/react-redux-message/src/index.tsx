import * as React from 'react';
import * as ReactDOM from 'react-dom';
import { connect, ComponentDecorator, Provider } from 'react-redux';
import { createStore, Store } from 'redux';

// Action
const SEND: string = 'SEND';

// Action Creator
interface ISendAction {
  type: string;
  value: string;
}

function send(value: string): ISendAction {
  return {
    type: SEND,
    value
  };
}

interface IState {
  value: string;
}

// Reducer
function formReducer(state: IState, action: ISendAction): IState {
  switch (action.type) {
    case 'SEND':
      return Object.assign({}, state, {
        value: action.value,
      });
    default:
      return state;
  }
}

const initialState: IState = {
  value: null,
};

const store: Store<IState> = createStore(formReducer, initialState);

// ----------- Index ------------------
// Interfaces for component
interface IProps {
  onClick: Function;
  value: string;
}

class Index extends React.Component <IProps, IState> {
// class Index extends React.Component <any, any> {
  constructor(props: IProps) {
    super(props);
  }
  render(): JSX.Element {
    return (
      <div>
        <FormInput handleClick={this.props.onClick} />
        <FormDisplay data={this.props.value} />
      </div>
    );
  }
}

// ----------- FormInput ------------------
interface IFormInputProps {
  handleClick: Function;
}

type Input  = {
  value: string;
};

class FormInput extends React.Component <IFormInputProps, void> {
  myInput: Input = { value: ''};
  constructor() {
    super();
  }
  send(e: any): void {
    e.preventDefault();
    this.props.handleClick(this.myInput.value.trim());
    this.myInput.value = '';
    return;
  }
  render(): JSX.Element {
    return(
      <form>
        <input type='text' ref={(ref) => {this.myInput = ref; }} defaultValue='' />
        <button onClick={(event) => this.send(event)}></button>
      </form>
    );
  }
}

// ----------- FormDisplay ------------------
interface IFormDisplayProps {
  data: string;
}

class FormDisplay extends React.Component <IFormDisplayProps, void> {
  render(): JSX.Element {
    return (
      <div>{this.props.data}</div>
    );
  }
}

// ------------ MapToProps ------------------
function mapStateToProps(state: IState): any {
  return {
    value: state.value
  };
}

// ------------ MapDispatchToProps------------------
interface ImapDispatchToProps {
  [key: string]: Function;
}
function mapDispatchToProps(dispatch: any): ImapDispatchToProps {
  return {
    onClick(value: string): void {
      dispatch(send(value));
    },
  };
}

const AppContainer: any = connect(
  mapStateToProps,
  mapDispatchToProps
)(Index);

ReactDOM.render(
  <Provider store={store}>
    <AppContainer />
  </Provider>,
  document.getElementById('content')
);
