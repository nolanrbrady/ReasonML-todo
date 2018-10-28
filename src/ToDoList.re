[%bs.raw {|require('./todolist.css')|}];

type state = {
    count: int,
};

type action =
  | Increment;  

let component = ReasonReact.reducerComponent("ToDoList");

let str = ReasonReact.string;

let make = (_children) => {
    ...component,

    initialState: () => {
        count: 0
    },

    reducer: (action, state) => {
        switch (action) {
        | Increment => ReasonReact.Update({ ...state, count: state.count + 1})
        };
    },

    render: _self => 
        <div className="container">
            <div className="list-container">
                <p>(str("Testing the Container"))</p>
                <p>(str(string_of_int(_self.state.count)))</p>
                <div onClick=(_event => _self.send(Increment)) className="button">
                    <p>(str("Increment Count"))</p>
                </div>
            </div>
        </div>,
};