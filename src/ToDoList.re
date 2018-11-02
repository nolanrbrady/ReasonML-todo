[%bs.raw {|require('./todolist.css')|}];

type item = {
    title: string,
    isComplete: bool
}

type state = {
    item: item,
    newItem: string,
    items: list(item)
};

type action =
  | AddItem(string)
  | SetNewItem(string);  

let component = ReasonReact.reducerComponent("ToDoList");

let str = ReasonReact.string;

let renderList = (items) => {
    let len = List.length(items);
    if (len === 0){
        (
            <div>
                <p className="empty-list">(str("Nothing Logged Yet"))</p>
            </div>
        );
    } else {
        items
        ->Belt.List.map((item) => (
            <div className="item-row">
                <h3 className="item-title-padding">(str(item.title))</h3>
                <input onClick=(_evt => Js.log("Testing the click")) type_="checkbox"/> 
            </div>
        ))
        ->Belt.List.toArray
        ->ReasonReact.array
    };
};

let addItemsToList = (item, list) => {
    let len = String.length(item);
    let newItem = {title: item, isComplete: false}
    let itemList = len !== 0 ? [newItem, ...list] : [...list];
    itemList;
}

let make = (_children) => {
    ...component,

    initialState: () => {
        item: { title: "", isComplete: false },
        newItem: "",
        items: []
    },

    reducer: (action, state) => {
        switch (action) {
        | AddItem(item) => ReasonReact.Update({ ...state, items: addItemsToList(item, state.items), newItem: "" })
        | SetNewItem(item) => ReasonReact.Update({ ...state, newItem: item})
        /* | HandleCheckBoxClick => ReasonReact.Upate({...state, items}) */
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
                <div className="button-row">
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