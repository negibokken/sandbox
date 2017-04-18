import * as React from 'react';
import * as ReactDOM from 'react-dom';
import { connect, InferableComponentDecorator, Provider } from 'react-redux';
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

interface IState {}

class Index extends React.Component <IProps, IState> {
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

class FormInput extends React.Component <IFormInputProps, void> {

}

// ----------- FormDisplay ------------------
interface IFormDisplayProps {
  data: string;
}

class FormDisplay extends React.Component <IFormDisplayProps, void> {

}

// ------------ MapToProps ------------------
function mapStateToProps(state: IState): void {
  /* */
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

const AppContainer: InferableComponentDecorator = connect(
  mapStateToProps,
  mapDispatchToProps
)(Index);

ReactDOM.render(
  <Index />,
  document.getElementById('content')
);
