// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bouncingBallsMessages.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bouncingBallsMessages_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bouncingBallsMessages_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bouncingBallsMessages_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bouncingBallsMessages_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bouncingBallsMessages_2eproto;
namespace ballProto {
class Ball;
class BallDefaultTypeInternal;
extern BallDefaultTypeInternal _Ball_default_instance_;
class stateUpdate;
class stateUpdateDefaultTypeInternal;
extern stateUpdateDefaultTypeInternal _stateUpdate_default_instance_;
}  // namespace ballProto
PROTOBUF_NAMESPACE_OPEN
template<> ::ballProto::Ball* Arena::CreateMaybeMessage<::ballProto::Ball>(Arena*);
template<> ::ballProto::stateUpdate* Arena::CreateMaybeMessage<::ballProto::stateUpdate>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ballProto {

// ===================================================================

class stateUpdate PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ballProto.stateUpdate) */ {
 public:
  inline stateUpdate() : stateUpdate(nullptr) {};
  virtual ~stateUpdate();

  stateUpdate(const stateUpdate& from);
  stateUpdate(stateUpdate&& from) noexcept
    : stateUpdate() {
    *this = ::std::move(from);
  }

  inline stateUpdate& operator=(const stateUpdate& from) {
    CopyFrom(from);
    return *this;
  }
  inline stateUpdate& operator=(stateUpdate&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const stateUpdate& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const stateUpdate* internal_default_instance() {
    return reinterpret_cast<const stateUpdate*>(
               &_stateUpdate_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(stateUpdate& a, stateUpdate& b) {
    a.Swap(&b);
  }
  inline void Swap(stateUpdate* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(stateUpdate* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline stateUpdate* New() const final {
    return CreateMaybeMessage<stateUpdate>(nullptr);
  }

  stateUpdate* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<stateUpdate>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const stateUpdate& from);
  void MergeFrom(const stateUpdate& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(stateUpdate* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ballProto.stateUpdate";
  }
  protected:
  explicit stateUpdate(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bouncingBallsMessages_2eproto);
    return ::descriptor_table_bouncingBallsMessages_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBallsFieldNumber = 1,
    kWorldShapeFieldNumber = 6,
    kBallCountFieldNumber = 2,
    kTimeUTCFieldNumber = 3,
    kXMaxFieldNumber = 4,
    kYMaxFieldNumber = 5,
    kCircleRadiusFieldNumber = 7,
  };
  // repeated .ballProto.Ball balls = 1;
  int balls_size() const;
  private:
  int _internal_balls_size() const;
  public:
  void clear_balls();
  ::ballProto::Ball* mutable_balls(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ballProto::Ball >*
      mutable_balls();
  private:
  const ::ballProto::Ball& _internal_balls(int index) const;
  ::ballProto::Ball* _internal_add_balls();
  public:
  const ::ballProto::Ball& balls(int index) const;
  ::ballProto::Ball* add_balls();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ballProto::Ball >&
      balls() const;

  // string worldShape = 6;
  void clear_worldshape();
  const std::string& worldshape() const;
  void set_worldshape(const std::string& value);
  void set_worldshape(std::string&& value);
  void set_worldshape(const char* value);
  void set_worldshape(const char* value, size_t size);
  std::string* mutable_worldshape();
  std::string* release_worldshape();
  void set_allocated_worldshape(std::string* worldshape);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_worldshape();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_worldshape(
      std::string* worldshape);
  private:
  const std::string& _internal_worldshape() const;
  void _internal_set_worldshape(const std::string& value);
  std::string* _internal_mutable_worldshape();
  public:

  // int32 ballCount = 2;
  void clear_ballcount();
  ::PROTOBUF_NAMESPACE_ID::int32 ballcount() const;
  void set_ballcount(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_ballcount() const;
  void _internal_set_ballcount(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 timeUTC = 3;
  void clear_timeutc();
  ::PROTOBUF_NAMESPACE_ID::int32 timeutc() const;
  void set_timeutc(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_timeutc() const;
  void _internal_set_timeutc(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 xMax = 4;
  void clear_xmax();
  ::PROTOBUF_NAMESPACE_ID::int32 xmax() const;
  void set_xmax(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_xmax() const;
  void _internal_set_xmax(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 yMax = 5;
  void clear_ymax();
  ::PROTOBUF_NAMESPACE_ID::int32 ymax() const;
  void set_ymax(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_ymax() const;
  void _internal_set_ymax(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 circleRadius = 7;
  void clear_circleradius();
  ::PROTOBUF_NAMESPACE_ID::int32 circleradius() const;
  void set_circleradius(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_circleradius() const;
  void _internal_set_circleradius(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:ballProto.stateUpdate)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ballProto::Ball > balls_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr worldshape_;
  ::PROTOBUF_NAMESPACE_ID::int32 ballcount_;
  ::PROTOBUF_NAMESPACE_ID::int32 timeutc_;
  ::PROTOBUF_NAMESPACE_ID::int32 xmax_;
  ::PROTOBUF_NAMESPACE_ID::int32 ymax_;
  ::PROTOBUF_NAMESPACE_ID::int32 circleradius_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_bouncingBallsMessages_2eproto;
};
// -------------------------------------------------------------------

class Ball PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ballProto.Ball) */ {
 public:
  inline Ball() : Ball(nullptr) {};
  virtual ~Ball();

  Ball(const Ball& from);
  Ball(Ball&& from) noexcept
    : Ball() {
    *this = ::std::move(from);
  }

  inline Ball& operator=(const Ball& from) {
    CopyFrom(from);
    return *this;
  }
  inline Ball& operator=(Ball&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Ball& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Ball* internal_default_instance() {
    return reinterpret_cast<const Ball*>(
               &_Ball_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Ball& a, Ball& b) {
    a.Swap(&b);
  }
  inline void Swap(Ball* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Ball* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Ball* New() const final {
    return CreateMaybeMessage<Ball>(nullptr);
  }

  Ball* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Ball>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Ball& from);
  void MergeFrom(const Ball& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Ball* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ballProto.Ball";
  }
  protected:
  explicit Ball(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bouncingBallsMessages_2eproto);
    return ::descriptor_table_bouncingBallsMessages_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 2,
    kYFieldNumber = 3,
    kVxFieldNumber = 4,
    kVyFieldNumber = 5,
    kRFieldNumber = 6,
    kIdFieldNumber = 1,
  };
  // double x = 2;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 3;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double vx = 4;
  void clear_vx();
  double vx() const;
  void set_vx(double value);
  private:
  double _internal_vx() const;
  void _internal_set_vx(double value);
  public:

  // double vy = 5;
  void clear_vy();
  double vy() const;
  void set_vy(double value);
  private:
  double _internal_vy() const;
  void _internal_set_vy(double value);
  public:

  // double r = 6;
  void clear_r();
  double r() const;
  void set_r(double value);
  private:
  double _internal_r() const;
  void _internal_set_r(double value);
  public:

  // int32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:ballProto.Ball)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  double vx_;
  double vy_;
  double r_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_bouncingBallsMessages_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// stateUpdate

// repeated .ballProto.Ball balls = 1;
inline int stateUpdate::_internal_balls_size() const {
  return balls_.size();
}
inline int stateUpdate::balls_size() const {
  return _internal_balls_size();
}
inline void stateUpdate::clear_balls() {
  balls_.Clear();
}
inline ::ballProto::Ball* stateUpdate::mutable_balls(int index) {
  // @@protoc_insertion_point(field_mutable:ballProto.stateUpdate.balls)
  return balls_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ballProto::Ball >*
stateUpdate::mutable_balls() {
  // @@protoc_insertion_point(field_mutable_list:ballProto.stateUpdate.balls)
  return &balls_;
}
inline const ::ballProto::Ball& stateUpdate::_internal_balls(int index) const {
  return balls_.Get(index);
}
inline const ::ballProto::Ball& stateUpdate::balls(int index) const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.balls)
  return _internal_balls(index);
}
inline ::ballProto::Ball* stateUpdate::_internal_add_balls() {
  return balls_.Add();
}
inline ::ballProto::Ball* stateUpdate::add_balls() {
  // @@protoc_insertion_point(field_add:ballProto.stateUpdate.balls)
  return _internal_add_balls();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::ballProto::Ball >&
stateUpdate::balls() const {
  // @@protoc_insertion_point(field_list:ballProto.stateUpdate.balls)
  return balls_;
}

// int32 ballCount = 2;
inline void stateUpdate::clear_ballcount() {
  ballcount_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::_internal_ballcount() const {
  return ballcount_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::ballcount() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.ballCount)
  return _internal_ballcount();
}
inline void stateUpdate::_internal_set_ballcount(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  ballcount_ = value;
}
inline void stateUpdate::set_ballcount(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_ballcount(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.ballCount)
}

// int32 timeUTC = 3;
inline void stateUpdate::clear_timeutc() {
  timeutc_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::_internal_timeutc() const {
  return timeutc_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::timeutc() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.timeUTC)
  return _internal_timeutc();
}
inline void stateUpdate::_internal_set_timeutc(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  timeutc_ = value;
}
inline void stateUpdate::set_timeutc(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_timeutc(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.timeUTC)
}

// int32 xMax = 4;
inline void stateUpdate::clear_xmax() {
  xmax_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::_internal_xmax() const {
  return xmax_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::xmax() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.xMax)
  return _internal_xmax();
}
inline void stateUpdate::_internal_set_xmax(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  xmax_ = value;
}
inline void stateUpdate::set_xmax(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_xmax(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.xMax)
}

// int32 yMax = 5;
inline void stateUpdate::clear_ymax() {
  ymax_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::_internal_ymax() const {
  return ymax_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::ymax() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.yMax)
  return _internal_ymax();
}
inline void stateUpdate::_internal_set_ymax(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  ymax_ = value;
}
inline void stateUpdate::set_ymax(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_ymax(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.yMax)
}

// string worldShape = 6;
inline void stateUpdate::clear_worldshape() {
  worldshape_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& stateUpdate::worldshape() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.worldShape)
  return _internal_worldshape();
}
inline void stateUpdate::set_worldshape(const std::string& value) {
  _internal_set_worldshape(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.worldShape)
}
inline std::string* stateUpdate::mutable_worldshape() {
  // @@protoc_insertion_point(field_mutable:ballProto.stateUpdate.worldShape)
  return _internal_mutable_worldshape();
}
inline const std::string& stateUpdate::_internal_worldshape() const {
  return worldshape_.Get();
}
inline void stateUpdate::_internal_set_worldshape(const std::string& value) {
  
  worldshape_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void stateUpdate::set_worldshape(std::string&& value) {
  
  worldshape_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:ballProto.stateUpdate.worldShape)
}
inline void stateUpdate::set_worldshape(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  worldshape_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:ballProto.stateUpdate.worldShape)
}
inline void stateUpdate::set_worldshape(const char* value,
    size_t size) {
  
  worldshape_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:ballProto.stateUpdate.worldShape)
}
inline std::string* stateUpdate::_internal_mutable_worldshape() {
  
  return worldshape_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* stateUpdate::release_worldshape() {
  // @@protoc_insertion_point(field_release:ballProto.stateUpdate.worldShape)
  return worldshape_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void stateUpdate::set_allocated_worldshape(std::string* worldshape) {
  if (worldshape != nullptr) {
    
  } else {
    
  }
  worldshape_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), worldshape,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:ballProto.stateUpdate.worldShape)
}
inline std::string* stateUpdate::unsafe_arena_release_worldshape() {
  // @@protoc_insertion_point(field_unsafe_arena_release:ballProto.stateUpdate.worldShape)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return worldshape_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void stateUpdate::unsafe_arena_set_allocated_worldshape(
    std::string* worldshape) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (worldshape != nullptr) {
    
  } else {
    
  }
  worldshape_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      worldshape, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:ballProto.stateUpdate.worldShape)
}

// int32 circleRadius = 7;
inline void stateUpdate::clear_circleradius() {
  circleradius_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::_internal_circleradius() const {
  return circleradius_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 stateUpdate::circleradius() const {
  // @@protoc_insertion_point(field_get:ballProto.stateUpdate.circleRadius)
  return _internal_circleradius();
}
inline void stateUpdate::_internal_set_circleradius(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  circleradius_ = value;
}
inline void stateUpdate::set_circleradius(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_circleradius(value);
  // @@protoc_insertion_point(field_set:ballProto.stateUpdate.circleRadius)
}

// -------------------------------------------------------------------

// Ball

// int32 id = 1;
inline void Ball::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Ball::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Ball::id() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.id)
  return _internal_id();
}
inline void Ball::_internal_set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
}
inline void Ball::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.id)
}

// double x = 2;
inline void Ball::clear_x() {
  x_ = 0;
}
inline double Ball::_internal_x() const {
  return x_;
}
inline double Ball::x() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.x)
  return _internal_x();
}
inline void Ball::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Ball::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.x)
}

// double y = 3;
inline void Ball::clear_y() {
  y_ = 0;
}
inline double Ball::_internal_y() const {
  return y_;
}
inline double Ball::y() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.y)
  return _internal_y();
}
inline void Ball::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Ball::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.y)
}

// double vx = 4;
inline void Ball::clear_vx() {
  vx_ = 0;
}
inline double Ball::_internal_vx() const {
  return vx_;
}
inline double Ball::vx() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.vx)
  return _internal_vx();
}
inline void Ball::_internal_set_vx(double value) {
  
  vx_ = value;
}
inline void Ball::set_vx(double value) {
  _internal_set_vx(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.vx)
}

// double vy = 5;
inline void Ball::clear_vy() {
  vy_ = 0;
}
inline double Ball::_internal_vy() const {
  return vy_;
}
inline double Ball::vy() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.vy)
  return _internal_vy();
}
inline void Ball::_internal_set_vy(double value) {
  
  vy_ = value;
}
inline void Ball::set_vy(double value) {
  _internal_set_vy(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.vy)
}

// double r = 6;
inline void Ball::clear_r() {
  r_ = 0;
}
inline double Ball::_internal_r() const {
  return r_;
}
inline double Ball::r() const {
  // @@protoc_insertion_point(field_get:ballProto.Ball.r)
  return _internal_r();
}
inline void Ball::_internal_set_r(double value) {
  
  r_ = value;
}
inline void Ball::set_r(double value) {
  _internal_set_r(value);
  // @@protoc_insertion_point(field_set:ballProto.Ball.r)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ballProto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bouncingBallsMessages_2eproto
