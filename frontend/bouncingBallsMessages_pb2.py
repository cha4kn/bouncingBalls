# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: bouncingBallsMessages.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='bouncingBallsMessages.proto',
  package='ballProto',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x1b\x62ouncingBallsMessages.proto\x12\tballProto\"m\n\x0bstateUpdate\x12\x1e\n\x05\x62\x61lls\x18\x01 \x03(\x0b\x32\x0f.ballProto.Ball\x12\x11\n\tballCount\x18\x02 \x01(\x05\x12\x0f\n\x07timeUTC\x18\x03 \x01(\x05\x12\x0c\n\x04xMax\x18\x04 \x01(\x05\x12\x0c\n\x04yMax\x18\x05 \x01(\x05\"K\n\x04\x42\x61ll\x12\n\n\x02id\x18\x01 \x01(\x05\x12\t\n\x01x\x18\x02 \x01(\x01\x12\t\n\x01y\x18\x03 \x01(\x01\x12\n\n\x02vx\x18\x04 \x01(\x01\x12\n\n\x02vy\x18\x05 \x01(\x01\x12\t\n\x01r\x18\x06 \x01(\x01\x62\x06proto3')
)




_STATEUPDATE = _descriptor.Descriptor(
  name='stateUpdate',
  full_name='ballProto.stateUpdate',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='balls', full_name='ballProto.stateUpdate.balls', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ballCount', full_name='ballProto.stateUpdate.ballCount', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='timeUTC', full_name='ballProto.stateUpdate.timeUTC', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='xMax', full_name='ballProto.stateUpdate.xMax', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='yMax', full_name='ballProto.stateUpdate.yMax', index=4,
      number=5, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=42,
  serialized_end=151,
)


_BALL = _descriptor.Descriptor(
  name='Ball',
  full_name='ballProto.Ball',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='ballProto.Ball.id', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='x', full_name='ballProto.Ball.x', index=1,
      number=2, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='y', full_name='ballProto.Ball.y', index=2,
      number=3, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='vx', full_name='ballProto.Ball.vx', index=3,
      number=4, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='vy', full_name='ballProto.Ball.vy', index=4,
      number=5, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='r', full_name='ballProto.Ball.r', index=5,
      number=6, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=153,
  serialized_end=228,
)

_STATEUPDATE.fields_by_name['balls'].message_type = _BALL
DESCRIPTOR.message_types_by_name['stateUpdate'] = _STATEUPDATE
DESCRIPTOR.message_types_by_name['Ball'] = _BALL
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

stateUpdate = _reflection.GeneratedProtocolMessageType('stateUpdate', (_message.Message,), dict(
  DESCRIPTOR = _STATEUPDATE,
  __module__ = 'bouncingBallsMessages_pb2'
  # @@protoc_insertion_point(class_scope:ballProto.stateUpdate)
  ))
_sym_db.RegisterMessage(stateUpdate)

Ball = _reflection.GeneratedProtocolMessageType('Ball', (_message.Message,), dict(
  DESCRIPTOR = _BALL,
  __module__ = 'bouncingBallsMessages_pb2'
  # @@protoc_insertion_point(class_scope:ballProto.Ball)
  ))
_sym_db.RegisterMessage(Ball)


# @@protoc_insertion_point(module_scope)
