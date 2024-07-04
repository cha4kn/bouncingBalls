from google.protobuf.internal import containers as _containers
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Iterable as _Iterable, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class Ball(_message.Message):
    __slots__ = ["id", "r", "x", "y"]
    ID_FIELD_NUMBER: _ClassVar[int]
    R_FIELD_NUMBER: _ClassVar[int]
    X_FIELD_NUMBER: _ClassVar[int]
    Y_FIELD_NUMBER: _ClassVar[int]
    id: int
    r: float
    x: float
    y: float
    def __init__(self, id: _Optional[int] = ..., x: _Optional[float] = ..., y: _Optional[float] = ..., r: _Optional[float] = ...) -> None: ...

class stateUpdate(_message.Message):
    __slots__ = ["ballCount", "balls", "timeUTC"]
    BALLCOUNT_FIELD_NUMBER: _ClassVar[int]
    BALLS_FIELD_NUMBER: _ClassVar[int]
    TIMEUTC_FIELD_NUMBER: _ClassVar[int]
    ballCount: int
    balls: _containers.RepeatedCompositeFieldContainer[Ball]
    timeUTC: int
    def __init__(self, balls: _Optional[_Iterable[_Union[Ball, _Mapping]]] = ..., ballCount: _Optional[int] = ..., timeUTC: _Optional[int] = ...) -> None: ...
