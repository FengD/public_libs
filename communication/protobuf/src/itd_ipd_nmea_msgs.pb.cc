// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: itd_ipd_nmea_msgs.proto

#include "itd_ipd_nmea_msgs.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace itd {
namespace communication {
namespace protobuf {
class Gps84DefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Gps84>
      _instance;
} _Gps84_default_instance_;
}  // namespace protobuf
}  // namespace communication
}  // namespace itd
namespace protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto {
void InitDefaultsGps84Impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  protobuf_itd_5fipd_5fstd_5fmsgs_2eproto::InitDefaultsHeader();
  {
    void* ptr = &::itd::communication::protobuf::_Gps84_default_instance_;
    new (ptr) ::itd::communication::protobuf::Gps84();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::itd::communication::protobuf::Gps84::InitAsDefaultInstance();
}

void InitDefaultsGps84() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsGps84Impl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, header_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, message_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, latitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, longitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, altitude_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, speed_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::itd::communication::protobuf::Gps84, utc_sec_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::itd::communication::protobuf::Gps84)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::itd::communication::protobuf::_Gps84_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "itd_ipd_nmea_msgs.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\027itd_ipd_nmea_msgs.proto\022\032itd.communica"
      "tion.protobuf\032\026itd_ipd_std_msgs.proto\"\246\001"
      "\n\005Gps84\0222\n\006header\030\001 \001(\0132\".itd.communicat"
      "ion.protobuf.Header\022\022\n\nmessage_id\030\002 \001(\t\022"
      "\020\n\010latitude\030\003 \001(\001\022\021\n\tlongitude\030\004 \001(\001\022\020\n\010"
      "altitude\030\005 \001(\001\022\r\n\005speed\030\006 \001(\002\022\017\n\007utc_sec"
      "\030\007 \001(\001B\003\370\001\001P\000b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 261);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "itd_ipd_nmea_msgs.proto", &protobuf_RegisterTypes);
  ::protobuf_itd_5fipd_5fstd_5fmsgs_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto
namespace itd {
namespace communication {
namespace protobuf {

// ===================================================================

void Gps84::InitAsDefaultInstance() {
  ::itd::communication::protobuf::_Gps84_default_instance_._instance.get_mutable()->header_ = const_cast< ::itd::communication::protobuf::Header*>(
      ::itd::communication::protobuf::Header::internal_default_instance());
}
void Gps84::_slow_mutable_header() {
  header_ = ::google::protobuf::Arena::CreateMessage< ::itd::communication::protobuf::Header >(
      GetArenaNoVirtual());
}
void Gps84::unsafe_arena_set_allocated_header(
    ::itd::communication::protobuf::Header* header) {
  if (GetArenaNoVirtual() == NULL) {
    delete header_;
  }
  header_ = header;
  if (header) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:itd.communication.protobuf.Gps84.header)
}
void Gps84::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Gps84::kHeaderFieldNumber;
const int Gps84::kMessageIdFieldNumber;
const int Gps84::kLatitudeFieldNumber;
const int Gps84::kLongitudeFieldNumber;
const int Gps84::kAltitudeFieldNumber;
const int Gps84::kSpeedFieldNumber;
const int Gps84::kUtcSecFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Gps84::Gps84()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::InitDefaultsGps84();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:itd.communication.protobuf.Gps84)
}
Gps84::Gps84(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::InitDefaultsGps84();
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:itd.communication.protobuf.Gps84)
}
Gps84::Gps84(const Gps84& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.message_id().size() > 0) {
    message_id_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_id(),
      GetArenaNoVirtual());
  }
  if (from.has_header()) {
    header_ = new ::itd::communication::protobuf::Header(*from.header_);
  } else {
    header_ = NULL;
  }
  ::memcpy(&latitude_, &from.latitude_,
    static_cast<size_t>(reinterpret_cast<char*>(&speed_) -
    reinterpret_cast<char*>(&latitude_)) + sizeof(speed_));
  // @@protoc_insertion_point(copy_constructor:itd.communication.protobuf.Gps84)
}

void Gps84::SharedCtor() {
  message_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&header_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&speed_) -
      reinterpret_cast<char*>(&header_)) + sizeof(speed_));
  _cached_size_ = 0;
}

Gps84::~Gps84() {
  // @@protoc_insertion_point(destructor:itd.communication.protobuf.Gps84)
  SharedDtor();
}

void Gps84::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == NULL);
  message_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete header_;
}

void Gps84::ArenaDtor(void* object) {
  Gps84* _this = reinterpret_cast< Gps84* >(object);
  (void)_this;
}
void Gps84::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void Gps84::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Gps84::descriptor() {
  ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Gps84& Gps84::default_instance() {
  ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::InitDefaultsGps84();
  return *internal_default_instance();
}

Gps84* Gps84::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<Gps84>(arena);
}

void Gps84::Clear() {
// @@protoc_insertion_point(message_clear_start:itd.communication.protobuf.Gps84)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  message_id_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
  ::memset(&latitude_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&speed_) -
      reinterpret_cast<char*>(&latitude_)) + sizeof(speed_));
  _internal_metadata_.Clear();
}

bool Gps84::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:itd.communication.protobuf.Gps84)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .itd.communication.protobuf.Header header = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_header()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string message_id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message_id().data(), static_cast<int>(this->message_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "itd.communication.protobuf.Gps84.message_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double latitude = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(25u /* 25 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &latitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double longitude = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &longitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double altitude = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(41u /* 41 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &altitude_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // float speed = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(53u /* 53 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &speed_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // double utc_sec = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(57u /* 57 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &utc_sec_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:itd.communication.protobuf.Gps84)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:itd.communication.protobuf.Gps84)
  return false;
#undef DO_
}

void Gps84::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:itd.communication.protobuf.Gps84)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .itd.communication.protobuf.Header header = 1;
  if (this->has_header()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->header_, output);
  }

  // string message_id = 2;
  if (this->message_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message_id().data(), static_cast<int>(this->message_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "itd.communication.protobuf.Gps84.message_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->message_id(), output);
  }

  // double latitude = 3;
  if (this->latitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->latitude(), output);
  }

  // double longitude = 4;
  if (this->longitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->longitude(), output);
  }

  // double altitude = 5;
  if (this->altitude() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->altitude(), output);
  }

  // float speed = 6;
  if (this->speed() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->speed(), output);
  }

  // double utc_sec = 7;
  if (this->utc_sec() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(7, this->utc_sec(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:itd.communication.protobuf.Gps84)
}

::google::protobuf::uint8* Gps84::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:itd.communication.protobuf.Gps84)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .itd.communication.protobuf.Header header = 1;
  if (this->has_header()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, *this->header_, deterministic, target);
  }

  // string message_id = 2;
  if (this->message_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message_id().data(), static_cast<int>(this->message_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "itd.communication.protobuf.Gps84.message_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->message_id(), target);
  }

  // double latitude = 3;
  if (this->latitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->latitude(), target);
  }

  // double longitude = 4;
  if (this->longitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->longitude(), target);
  }

  // double altitude = 5;
  if (this->altitude() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->altitude(), target);
  }

  // float speed = 6;
  if (this->speed() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->speed(), target);
  }

  // double utc_sec = 7;
  if (this->utc_sec() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(7, this->utc_sec(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:itd.communication.protobuf.Gps84)
  return target;
}

size_t Gps84::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:itd.communication.protobuf.Gps84)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string message_id = 2;
  if (this->message_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message_id());
  }

  // .itd.communication.protobuf.Header header = 1;
  if (this->has_header()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *this->header_);
  }

  // double latitude = 3;
  if (this->latitude() != 0) {
    total_size += 1 + 8;
  }

  // double longitude = 4;
  if (this->longitude() != 0) {
    total_size += 1 + 8;
  }

  // double altitude = 5;
  if (this->altitude() != 0) {
    total_size += 1 + 8;
  }

  // double utc_sec = 7;
  if (this->utc_sec() != 0) {
    total_size += 1 + 8;
  }

  // float speed = 6;
  if (this->speed() != 0) {
    total_size += 1 + 4;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Gps84::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:itd.communication.protobuf.Gps84)
  GOOGLE_DCHECK_NE(&from, this);
  const Gps84* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Gps84>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:itd.communication.protobuf.Gps84)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:itd.communication.protobuf.Gps84)
    MergeFrom(*source);
  }
}

void Gps84::MergeFrom(const Gps84& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:itd.communication.protobuf.Gps84)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.message_id().size() > 0) {
    set_message_id(from.message_id());
  }
  if (from.has_header()) {
    mutable_header()->::itd::communication::protobuf::Header::MergeFrom(from.header());
  }
  if (from.latitude() != 0) {
    set_latitude(from.latitude());
  }
  if (from.longitude() != 0) {
    set_longitude(from.longitude());
  }
  if (from.altitude() != 0) {
    set_altitude(from.altitude());
  }
  if (from.utc_sec() != 0) {
    set_utc_sec(from.utc_sec());
  }
  if (from.speed() != 0) {
    set_speed(from.speed());
  }
}

void Gps84::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:itd.communication.protobuf.Gps84)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Gps84::CopyFrom(const Gps84& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:itd.communication.protobuf.Gps84)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Gps84::IsInitialized() const {
  return true;
}

void Gps84::Swap(Gps84* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    Gps84* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == NULL) {
      delete temp;
    }
  }
}
void Gps84::UnsafeArenaSwap(Gps84* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void Gps84::InternalSwap(Gps84* other) {
  using std::swap;
  message_id_.Swap(&other->message_id_);
  swap(header_, other->header_);
  swap(latitude_, other->latitude_);
  swap(longitude_, other->longitude_);
  swap(altitude_, other->altitude_);
  swap(utc_sec_, other->utc_sec_);
  swap(speed_, other->speed_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Gps84::GetMetadata() const {
  protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_itd_5fipd_5fnmea_5fmsgs_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace protobuf
}  // namespace communication
}  // namespace itd

// @@protoc_insertion_point(global_scope)