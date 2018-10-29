[%bs.raw {|require('./todolist.css')|}];

type state = {
    count: int,
    newItem: string,
    list: list(string)
};

type action =
  | Increment
  | AddItem
  | SetNewItem(string);  

let component = ReasonReact.reducerComponent("ToDoList");

let str = ReasonReact.string;

/* Increment the Timer Count */
let incrementCount = (count) => {
    count + 1
};

/* Append an Item to the To Do List  */
let appendItemToList = (currentList: list(string), item: string) => {
    Js.log(str(item));
   let updatedList = [ item , ...currentList];
   updatedList;
};

let make = (_children) => {
    ...component,

    initialState: () => {
        count: 0,
        newItem: "test",
        list: ["First Time"]
    },

    reducer: (action, state) => {
        switch (action) {
        | Increment => ReasonReact.Update({ ...state, count: incrementCount( state.count )});
        | AddItem => ReasonReact.Update({ ...state, list: appendItemToList( state.list, state.newItem )})
        | SetNewItem(item) => ReasonReact.Update({ ...state, newItem: item})
        };
    },

    render: _self => 
        <div className="container">
            <div className="list-container">
                <p>(str("Testing the Container"))</p>
                <div className="input-area">
                <form>
                    <input 
                        className="input-field" 
                        value=(_self.state.newItem) 
                        target="newItem"
                        name="newItem" 
                        onChange=(_event => _self.send(SetNewItem(ReactEvent.Form.target(_event)##newItem))) />
                </form>
                    <button onClick=(_event => _self.send(AddItem))>(str("Set Item"))</button>
                </div>
                <p>(str(string_of_int(_self.state.count)))</p>
                <div onClick=(_event => _self.send(Increment)) className="button">
                    <p className="button-text">(str("Increment Count"))</p>
                </div>
            </div>
        </div>,
};