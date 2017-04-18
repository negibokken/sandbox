import * as React from 'react';
import * as ReactDOM from 'react-dom';

interface IProps {}

interface IState {}

class Index extends React.Component <IProps, IState> {
  constructor(props: IProps) {
    super(props);
  }

  render(): JSX.Element {
    return (
      <div>
        hello world
      </div>
    );
  }
}

ReactDOM.render(
  <Index />,
  document.getElementById('content')
);
