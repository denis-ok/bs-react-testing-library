open DomTestingLibrary;

module FireEvent = {
  include FireEvent;
};

type renderResult;
type queries;
type renderOptions = {
  .
  "container": Js.undefined(Dom.element),
  "baseElement": Js.undefined(Dom.element),
  "hydrate": Js.undefined(bool),
  "wrapper": Js.undefined(Dom.element),
  "queries": Js.undefined(queries),
};

[@bs.module "@testing-library/react"]
external cleanup: unit => Js.Promise.t(unit) = "cleanup";

[@bs.module "@testing-library/react"]
external _act: (unit => Js.undefined(Js.Promise.t('a))) => unit = "act";

let act = callback =>
  _act(() => {
    callback();
    // (work-around) BuckleScript compiles `unit` to `0`, this will cause a warning as following:
    // Warning: The callback passed to act(...) function must return undefined, or a Promise.
    Js.Undefined.empty;
  });

[@bs.module "@testing-library/react"]
external _render: (ReasonReact.reactElement, renderOptions) => renderResult =
  "render";

[@bs.get] external container: renderResult => Dom.element = "container";

[@bs.get] external baseElement: renderResult => Dom.element = "baseElement";

[@bs.send.pipe: renderResult]
external _debug: (Js.undefined(Dom.element), Js.undefined(int)) => unit =
  "debug";

[@bs.send.pipe: renderResult] external unmount: unit => bool = "unmount";

[@bs.send.pipe: renderResult]
external rerender: ReasonReact.reactElement => unit = "rerender";

[@bs.send.pipe: renderResult]
external asFragment: unit => Dom.element = "asFragment";

// ByLabelText
[@bs.send.pipe: renderResult]
external _getByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  Dom.element =
  "getByLabelText";

let getByLabelText = (~matcher, ~options=?, result) =>
  _getByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _getAllByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByLabelText";

let getAllByLabelText = (~matcher, ~options=?, result) =>
  _getAllByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByLabelText";

let queryByLabelText = (~matcher, ~options=?, result) =>
  _queryByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryAllByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByLabelText";

let queryAllByLabelText = (~matcher, ~options=?, result) =>
  _queryAllByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByLabelText";

let findByLabelText = (~matcher, ~options=?, result) =>
  _findByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findAllByLabelText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByLabelTextQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByLabelText";

let findAllByLabelText = (~matcher, ~options=?, result) =>
  _findAllByLabelText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByPlaceholderText
[@bs.send.pipe: renderResult]
external _getByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  Dom.element =
  "getByPlaceholderText";

let getByPlaceholderText = (~matcher, ~options=?, result) =>
  _getByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _getAllByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByPlaceholderText";

let getAllByPlaceholderText = (~matcher, ~options=?, result) =>
  _getAllByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByPlaceholderText";

let queryByPlaceholderText = (~matcher, ~options=?, result) =>
  _queryByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryAllByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByPlaceholderText";

let queryAllByPlaceholderText = (~matcher, ~options=?, result) =>
  _queryAllByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByPlaceholderText";

let findByPlaceholderText = (~matcher, ~options=?, result) =>
  _findByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findAllByPlaceholderText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByPlaceholderTextQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByPlaceholderText";

let findAllByPlaceholderText = (~matcher, ~options=?, result) =>
  _findAllByPlaceholderText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByText
[@bs.send.pipe: renderResult]
external _getByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  Dom.element =
  "getByText";

let getByText = (~matcher, ~options=?, result) =>
  _getByText(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _getAllByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByText";

let getAllByText = (~matcher, ~options=?, result) =>
  _getAllByText(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _queryByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByText";

let queryByText = (~matcher, ~options=?, result) =>
  _queryByText(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _queryAllByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByText";

let queryAllByText = (~matcher, ~options=?, result) =>
  _queryAllByText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByText";

let findByText = (~matcher, ~options=?, result) =>
  _findByText(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _findAllByText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTextQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByText";

let findAllByText = (~matcher, ~options=?, result) =>
  _findAllByText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByAltText
[@bs.send.pipe: renderResult]
external _getByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  Dom.element =
  "getByAltText";

let getByAltText = (~matcher, ~options=?, result) =>
  _getByAltText(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _getAllByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByAltText";

let getAllByAltText = (~matcher, ~options=?, result) =>
  _getAllByAltText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByAltText";

let queryByAltText = (~matcher, ~options=?, result) =>
  _queryByAltText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryAllByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByAltText";

let queryAllByAltText = (~matcher, ~options=?, result) =>
  _queryAllByAltText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByAltText";

let findByAltText = (~matcher, ~options=?, result) =>
  _findByAltText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findAllByAltText:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByAltTextQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByAltText";

let findAllByAltText = (~matcher, ~options=?, result) =>
  _findAllByAltText(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByTitle
[@bs.send.pipe: renderResult]
external _getByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  Dom.element =
  "getByTitle";

let getByTitle = (~matcher, ~options=?, result) =>
  _getByTitle(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _getAllByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByTitle";

let getAllByTitle = (~matcher, ~options=?, result) =>
  _getAllByTitle(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByTitle";

let queryByTitle = (~matcher, ~options=?, result) =>
  _queryByTitle(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _queryAllByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByTitle";

let queryAllByTitle = (~matcher, ~options=?, result) =>
  _queryAllByTitle(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByTitle";

let findByTitle = (~matcher, ~options=?, result) =>
  _findByTitle(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _findAllByTitle:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTitleQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByTitle";

let findAllByTitle = (~matcher, ~options=?, result) =>
  _findAllByTitle(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByDisplayValue
[@bs.send.pipe: renderResult]
external _getByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  Dom.element =
  "getByDisplayValue";

let getByDisplayValue = (~matcher, ~options=?, result) =>
  _getByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _getAllByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByDisplayValue";

let getAllByDisplayValue = (~matcher, ~options=?, result) =>
  _getAllByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByDisplayValue";

let queryByDisplayValue = (~matcher, ~options=?, result) =>
  _queryByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryAllByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByDisplayValue";

let queryAllByDisplayValue = (~matcher, ~options=?, result) =>
  _queryAllByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByDisplayValue";

let findByDisplayValue = (~matcher, ~options=?, result) =>
  _findByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findAllByDisplayValue:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByDisplayValueQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByDisplayValue";

let findAllByDisplayValue = (~matcher, ~options=?, result) =>
  _findAllByDisplayValue(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByRole
[@bs.send.pipe: renderResult]
external _getByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  Dom.element =
  "getByRole";

let getByRole = (~matcher, ~options=?, result) =>
  _getByRole(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _getAllByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByRole";

let getAllByRole = (~matcher, ~options=?, result) =>
  _getAllByRole(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _queryByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByRole";

let queryByRole = (~matcher, ~options=?, result) =>
  _queryByRole(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _queryAllByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByRole";

let queryAllByRole = (~matcher, ~options=?, result) =>
  _queryAllByRole(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByRole";

let findByRole = (~matcher, ~options=?, result) =>
  _findByRole(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _findAllByRole:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByRoleQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByRole";

let findAllByRole = (~matcher, ~options=?, result) =>
  _findAllByRole(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

// ByTestId
[@bs.send.pipe: renderResult]
external _getByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  Dom.element =
  "getByTestId";

let getByTestId = (~matcher, ~options=?, result) =>
  _getByTestId(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _getAllByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  array(Dom.element) =
  "getAllByTestId";

let getAllByTestId = (~matcher, ~options=?, result) =>
  _getAllByTestId(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  Js.null(Dom.element) =
  "queryByTestId";

let queryByTestId = (~matcher, ~options=?, result) =>
  _queryByTestId(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _queryAllByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  array(Dom.element) =
  "queryAllByTestId";

let queryAllByTestId = (~matcher, ~options=?, result) =>
  _queryAllByTestId(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

[@bs.send.pipe: renderResult]
external _findByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  Js.Promise.t(Dom.element) =
  "findByTestId";

let findByTestId = (~matcher, ~options=?, result) =>
  _findByTestId(result, ~matcher, ~options=Js.Undefined.fromOption(options));

[@bs.send.pipe: renderResult]
external _findAllByTestId:
  (
    ~matcher: [@bs.unwrap] [
                | `Str(string)
                | `RegExp(Js.Re.t)
                | `Func((string, Dom.element) => bool)
              ],
    ~options: Js.undefined(ByTestIdQuery.options)
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByTestId";

let findAllByTestId = (~matcher, ~options=?, result) =>
  _findAllByTestId(
    result,
    ~matcher,
    ~options=Js.Undefined.fromOption(options),
  );

let render =
    (
      ~baseElement=?,
      ~container=?,
      ~hydrate=?,
      ~wrapper=?,
      ~queries=?,
      element,
    ) => {
  let baseElement_ =
    switch (container) {
    | Some(container') => Js.Undefined.return(container')
    | None => Js.Undefined.fromOption(baseElement)
    };
  let container_ = Js.Undefined.fromOption(container);

  _render(
    element,
    {
      "baseElement": baseElement_,
      "container": container_,
      "hydrate": Js.Undefined.fromOption(hydrate),
      "wrapper": Js.Undefined.fromOption(wrapper),
      "queries": Js.Undefined.fromOption(queries),
    },
  );
};

let debug = (~el=?, ~maxLengthToPrint=?, ()) =>
  _debug(
    Js.Undefined.fromOption(el),
    Js.Undefined.fromOption(maxLengthToPrint),
  );
