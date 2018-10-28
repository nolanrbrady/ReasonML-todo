
type state = {
    count: int,
};

type action = 
  | Click;


let component = ReasonReact.reducerComponent("TopBar");

let str = ReasonReact.string;


let style = Css.(
    {
        "header":
          style([
            backgroundColor(rgba(238, 35, 45, 1.0)),
            display(`flex),
            justifyContent(center),
            paddingTop(px(30)),
            paddingBottom(px(30)),
            alignItems(center)
          ]),
        "title": style([color(white), fontSize(px(36)), fontWeight(500)]),
        "logo": style([width(px(200)), height(px(80)), marginLeft(px(32)), borderWidth(px(2)), borderColor(blue) ]),
        "search_input_wrapper":style([marginRight(px(32))]),
        "search_input": style([marginRight(px(8))])
      }
);

let make = (_children) => {
    ...component, 
    initialState: () => {
        count: 0
    },
    reducer: (action, state) => {
       switch(action) {
       | Click => ReasonReact.Update({ ...state, count: state.count + 1 })
       }
    },

    render: (_self) => 
    <header className=style##header>
       /* <h4>(str(string_of_int(_self.state.count)))</h4> */
        <span className=style##title>(str("To Do List in ReasonML"))</span>
        /* <div className=style##search_input_wrapper>
            <input className=style##search_input placeholder="search" />
            <button onClick=(_event => _self.send(Click))>(str("Search"))</button>
        </div> */
    </header>
};