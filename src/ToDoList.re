[%bs.raw {|require('./todolist.css')|}];

type state = {
    count: int,
    newItem: string,
    items: list(string)
};

type action =
  | Increment
  | AddItem(string)
  | SetNewItem(string);  

let component = ReasonReact.reducerComponent("ToDoList");

let str = ReasonReact.string;

/* Increment the Timer Count using an external function */
let incrementCount = (count) => {
    count + 1
};

let renderList = (items) => {
    (
    items
        ->Belt.List.map((item) => <p>(str(item))</p>)
        ->Belt.List.toArray
        ->ReasonReact.array
    );
}

let make = (_children) => {
    ...component,

    initialState: () => {
        count: 0,
        newItem: "",
        items: ["Testing The Items"]
    },

    reducer: (action, state) => {
        switch (action) {
        | Increment => ReasonReact.Update({ ...state, count: incrementCount( state.count )});
        | AddItem(item) => ReasonReact.Update({ ...state, items: [item, ...state.items], newItem: "" })
        | SetNewItem(item) => ReasonReact.Update({ ...state, newItem: item})
        };
    },

    render: _self => {
    let listLength = List.length(_self.state.items);
       <div>
        <div className="container">
            <div className="list-container">
                <h3>(str("To Do Items"))</h3>
                <div className="input-area">
                <form>
                    <input 
                        className="input-field" 
                        value=(_self.state.newItem) 
                        target="newItem"
                        name="newItem" 
                        placeholder="Enter your To Do Item"
                        onChange=(_event => _self.send(SetNewItem(ReactEvent.Form.target(_event)##value))) />
                </form>
                </div>
                <div>(renderList(_self.state.items))</div>
                <div>
                    <h4>(str("Items in List " ++ string_of_int(listLength)))</h4>
                </div>
                <div className="button-row">
                    <div onClick=(_event => _self.send(Increment)) className="button">
                        <p className="button-text">(str("Increment Count"))</p>
                    </div>
                    <div onClick=(_event => _self.send(AddItem(_self.state.newItem))) className="button">
                        <p className="button-text">(str("Add Item To List"))</p>
                    </div>
                </div>
            </div>
            </div>
        <Footer item=(string_of_int(listLength))/>
       </div>
    }
};