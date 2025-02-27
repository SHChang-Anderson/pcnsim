//
// Generated file, do not edit! Created by opp_msgtool 6.1 from updateAddHTLC.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "updateAddHTLC_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(UpdateAddHTLC)

UpdateAddHTLC::UpdateAddHTLC(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

UpdateAddHTLC::UpdateAddHTLC(const UpdateAddHTLC& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

UpdateAddHTLC::~UpdateAddHTLC()
{
}

UpdateAddHTLC& UpdateAddHTLC::operator=(const UpdateAddHTLC& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UpdateAddHTLC::copy(const UpdateAddHTLC& other)
{
    this->source = other.source;
    this->htlcId = other.htlcId;
    this->paymentHash = other.paymentHash;
    this->timeout = other.timeout;
    this->value = other.value;
}

void UpdateAddHTLC::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->source);
    doParsimPacking(b,this->htlcId);
    doParsimPacking(b,this->paymentHash);
    doParsimPacking(b,this->timeout);
    doParsimPacking(b,this->value);
}

void UpdateAddHTLC::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->source);
    doParsimUnpacking(b,this->htlcId);
    doParsimUnpacking(b,this->paymentHash);
    doParsimUnpacking(b,this->timeout);
    doParsimUnpacking(b,this->value);
}

const char * UpdateAddHTLC::getSource() const
{
    return this->source.c_str();
}

void UpdateAddHTLC::setSource(const char * source)
{
    this->source = source;
}

const char * UpdateAddHTLC::getHtlcId() const
{
    return this->htlcId.c_str();
}

void UpdateAddHTLC::setHtlcId(const char * htlcId)
{
    this->htlcId = htlcId;
}

const char * UpdateAddHTLC::getPaymentHash() const
{
    return this->paymentHash.c_str();
}

void UpdateAddHTLC::setPaymentHash(const char * paymentHash)
{
    this->paymentHash = paymentHash;
}

omnetpp::simtime_t UpdateAddHTLC::getTimeout() const
{
    return this->timeout;
}

void UpdateAddHTLC::setTimeout(omnetpp::simtime_t timeout)
{
    this->timeout = timeout;
}

double UpdateAddHTLC::getValue() const
{
    return this->value;
}

void UpdateAddHTLC::setValue(double value)
{
    this->value = value;
}

class UpdateAddHTLCDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_source,
        FIELD_htlcId,
        FIELD_paymentHash,
        FIELD_timeout,
        FIELD_value,
    };
  public:
    UpdateAddHTLCDescriptor();
    virtual ~UpdateAddHTLCDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UpdateAddHTLCDescriptor)

UpdateAddHTLCDescriptor::UpdateAddHTLCDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UpdateAddHTLC)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

UpdateAddHTLCDescriptor::~UpdateAddHTLCDescriptor()
{
    delete[] propertyNames;
}

bool UpdateAddHTLCDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UpdateAddHTLC *>(obj)!=nullptr;
}

const char **UpdateAddHTLCDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UpdateAddHTLCDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UpdateAddHTLCDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int UpdateAddHTLCDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_source
        FD_ISEDITABLE,    // FIELD_htlcId
        FD_ISEDITABLE,    // FIELD_paymentHash
        FD_ISEDITABLE,    // FIELD_timeout
        FD_ISEDITABLE,    // FIELD_value
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *UpdateAddHTLCDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "source",
        "htlcId",
        "paymentHash",
        "timeout",
        "value",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int UpdateAddHTLCDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "source") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "htlcId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "paymentHash") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "timeout") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "value") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *UpdateAddHTLCDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_source
        "string",    // FIELD_htlcId
        "string",    // FIELD_paymentHash
        "omnetpp::simtime_t",    // FIELD_timeout
        "double",    // FIELD_value
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **UpdateAddHTLCDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UpdateAddHTLCDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UpdateAddHTLCDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UpdateAddHTLCDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UpdateAddHTLC'", field);
    }
}

const char *UpdateAddHTLCDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UpdateAddHTLCDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        case FIELD_source: return oppstring2string(pp->getSource());
        case FIELD_htlcId: return oppstring2string(pp->getHtlcId());
        case FIELD_paymentHash: return oppstring2string(pp->getPaymentHash());
        case FIELD_timeout: return simtime2string(pp->getTimeout());
        case FIELD_value: return double2string(pp->getValue());
        default: return "";
    }
}

void UpdateAddHTLCDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        case FIELD_source: pp->setSource((value)); break;
        case FIELD_htlcId: pp->setHtlcId((value)); break;
        case FIELD_paymentHash: pp->setPaymentHash((value)); break;
        case FIELD_timeout: pp->setTimeout(string2simtime(value)); break;
        case FIELD_value: pp->setValue(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateAddHTLC'", field);
    }
}

omnetpp::cValue UpdateAddHTLCDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        case FIELD_source: return pp->getSource();
        case FIELD_htlcId: return pp->getHtlcId();
        case FIELD_paymentHash: return pp->getPaymentHash();
        case FIELD_timeout: return pp->getTimeout().dbl();
        case FIELD_value: return pp->getValue();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UpdateAddHTLC' as cValue -- field index out of range?", field);
    }
}

void UpdateAddHTLCDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        case FIELD_source: pp->setSource(value.stringValue()); break;
        case FIELD_htlcId: pp->setHtlcId(value.stringValue()); break;
        case FIELD_paymentHash: pp->setPaymentHash(value.stringValue()); break;
        case FIELD_timeout: pp->setTimeout(value.doubleValue()); break;
        case FIELD_value: pp->setValue(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateAddHTLC'", field);
    }
}

const char *UpdateAddHTLCDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UpdateAddHTLCDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UpdateAddHTLCDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateAddHTLC *pp = omnetpp::fromAnyPtr<UpdateAddHTLC>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateAddHTLC'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

