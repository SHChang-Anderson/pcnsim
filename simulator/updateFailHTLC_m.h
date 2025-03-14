//
// Generated file, do not edit! Created by opp_msgtool 6.1 from updateFailHTLC.msg.
//

#ifndef __UPDATEFAILHTLC_M_H
#define __UPDATEFAILHTLC_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0601
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class UpdateFailHTLC;
// cplusplus {{
    #include <string>
    #include "messages.h"
// }}

/**
 * Class generated from <tt>updateFailHTLC.msg:6</tt> by opp_msgtool.
 * <pre>
 * packet UpdateFailHTLC
 * {
 *     string htlcId;
 *     string paymentHash;
 *     string errorReason;
 *     double value;
 * }
 * </pre>
 */
class UpdateFailHTLC : public ::omnetpp::cPacket
{
  protected:
    omnetpp::opp_string htlcId;
    omnetpp::opp_string paymentHash;
    omnetpp::opp_string errorReason;
    double value = 0;

  private:
    void copy(const UpdateFailHTLC& other);

  protected:
    bool operator==(const UpdateFailHTLC&) = delete;

  public:
    UpdateFailHTLC(const char *name=nullptr, short kind=0);
    UpdateFailHTLC(const UpdateFailHTLC& other);
    virtual ~UpdateFailHTLC();
    UpdateFailHTLC& operator=(const UpdateFailHTLC& other);
    virtual UpdateFailHTLC *dup() const override {return new UpdateFailHTLC(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const char * getHtlcId() const;
    virtual void setHtlcId(const char * htlcId);

    virtual const char * getPaymentHash() const;
    virtual void setPaymentHash(const char * paymentHash);

    virtual const char * getErrorReason() const;
    virtual void setErrorReason(const char * errorReason);

    virtual double getValue() const;
    virtual void setValue(double value);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UpdateFailHTLC& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UpdateFailHTLC& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline UpdateFailHTLC *fromAnyPtr(any_ptr ptr) { return check_and_cast<UpdateFailHTLC*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __UPDATEFAILHTLC_M_H

