-module(gate_tests).
-include_lib("eunit/include/eunit.hrl").

gate_test() ->
    {{_, _, D}, _} = calendar:now_to_datetime(erlang:now()),
    {{_, _, D}, _} = calendar:now_to_datetime(gate:approxidate("now")).

