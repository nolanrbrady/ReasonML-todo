[%bs.raw {|require('./todolist.css')|}];

let component = ReasonReact.statelessComponent("ToDoList");

let str = ReasonReact.string;

let make = (_children) => {
    ...component,
    render: _self => 
        <div className="container">
            <div className="list-container">
                <p>(str("Testing the Container"))</p>
            </div>
        </div>,
};