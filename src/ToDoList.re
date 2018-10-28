[%bs.raw {|require('./todolist.css')|}];

type state = {
    count: int,
    newItem: string,
};

type action =
  | Increment
  | AddItem;  

let component = ReasonReact.reducerComponent("ToDoList");

let str = ReasonReact.string;

/* Increment the Timer Count */
let incrementCount = (count) => {
    count + 1
};

let make = (_children) => {
    ...component,

    initialState: () => {
        count: 0,
        newItem: "Placeholder",
    },

    reducer: (action, state) => {
        switch (action) {
        | Increment => ReasonReact.Update({ ...state, count: incrementCount(state.count)});
        | AddItem => ReasonReact.Update({ ...state, newItem: "placeholder"})
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