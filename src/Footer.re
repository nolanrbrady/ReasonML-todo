

let component = ReasonReact.statelessComponent("Footer");

let str = ReasonReact.string;

let make = (~item, _children) => {
    ...component,
    render: _self => {
        <footer>
            <h4>(str("You have " ++ item ++ " item(s) on your To Do List"))</h4>
        </footer>
    }
};