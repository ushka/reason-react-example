type item = {
  title: string,
  completed: bool
};

type state = {
  items: list(item)
};

let component = ReasonReact.reducerComponent("Todo");

let str = ReasonReact.stringToElement;

let make = (children) => {
  ...component,
  initialState: () => {
    items: [
      {
      	title: "Write some things to do", 
      	completed: false
      }
    ]
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) => {
    let numItems = List.length(items);
    let message = numItems > 1 ? " items" : " item";
    <div className="app">
      <div className="title"> (str("What to do")) </div>
      <div className="items"> (str("Nothing")) </div>
      <div className="footer">
        (str(string_of_int(numItems) ++ message))
      </div>
    </div>
  }
};
