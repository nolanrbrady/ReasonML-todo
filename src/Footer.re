

let component = ReasonReact.statelessComponent("Footer");

let str = ReasonReact.string;

let make = (_children) => {
    ...component,
    render: _self => {
        <footer>
            <h4>(str("Testing the Footer"))</h4>
        </footer>
    }
};