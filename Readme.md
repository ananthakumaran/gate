Gate
=====

Erlang bindings for git natural language date parser


Usage
-----

    Eshell V5.9.2  (abort with ^G)
    1> calendar:now_to_datetime(gate:approxidate("now")).
    {{2013,1,9},{10,22,16}}
    2> calendar:now_to_datetime(gate:approxidate("yesterday")).
    {{2013,1,8},{10,22,21}}
    3> calendar:now_to_datetime(gate:approxidate("5 days ago")).
    {{2013,1,4},{10,22,27}}
    4> q().
    ok


