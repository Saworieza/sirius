/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SennaService_H
#define SennaService_H

#include <thrift/TDispatchProcessor.h>
#include "SennaService_types.h"



class SennaServiceIf {
 public:
  virtual ~SennaServiceIf() {}
  virtual void senna_all(std::string& _return, const std::string& inputs) = 0;
};

class SennaServiceIfFactory {
 public:
  typedef SennaServiceIf Handler;

  virtual ~SennaServiceIfFactory() {}

  virtual SennaServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SennaServiceIf* /* handler */) = 0;
};

class SennaServiceIfSingletonFactory : virtual public SennaServiceIfFactory {
 public:
  SennaServiceIfSingletonFactory(const boost::shared_ptr<SennaServiceIf>& iface) : iface_(iface) {}
  virtual ~SennaServiceIfSingletonFactory() {}

  virtual SennaServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SennaServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<SennaServiceIf> iface_;
};

class SennaServiceNull : virtual public SennaServiceIf {
 public:
  virtual ~SennaServiceNull() {}
  void senna_all(std::string& /* _return */, const std::string& /* inputs */) {
    return;
  }
};

typedef struct _SennaService_senna_all_args__isset {
  _SennaService_senna_all_args__isset() : inputs(false) {}
  bool inputs :1;
} _SennaService_senna_all_args__isset;

class SennaService_senna_all_args {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

  SennaService_senna_all_args(const SennaService_senna_all_args&);
  SennaService_senna_all_args& operator=(const SennaService_senna_all_args&);
  SennaService_senna_all_args() : inputs() {
  }

  virtual ~SennaService_senna_all_args() throw();
  std::string inputs;

  _SennaService_senna_all_args__isset __isset;

  void __set_inputs(const std::string& val);

  bool operator == (const SennaService_senna_all_args & rhs) const
  {
    if (!(inputs == rhs.inputs))
      return false;
    return true;
  }
  bool operator != (const SennaService_senna_all_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SennaService_senna_all_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const SennaService_senna_all_args& obj);
};


class SennaService_senna_all_pargs {
 public:

  static const char* ascii_fingerprint; // = "EFB929595D312AC8F305D5A794CFEDA1";
  static const uint8_t binary_fingerprint[16]; // = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};


  virtual ~SennaService_senna_all_pargs() throw();
  const std::string* inputs;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const SennaService_senna_all_pargs& obj);
};

typedef struct _SennaService_senna_all_result__isset {
  _SennaService_senna_all_result__isset() : success(false) {}
  bool success :1;
} _SennaService_senna_all_result__isset;

class SennaService_senna_all_result {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};

  SennaService_senna_all_result(const SennaService_senna_all_result&);
  SennaService_senna_all_result& operator=(const SennaService_senna_all_result&);
  SennaService_senna_all_result() : success() {
  }

  virtual ~SennaService_senna_all_result() throw();
  std::string success;

  _SennaService_senna_all_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const SennaService_senna_all_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SennaService_senna_all_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SennaService_senna_all_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  friend std::ostream& operator<<(std::ostream& out, const SennaService_senna_all_result& obj);
};

typedef struct _SennaService_senna_all_presult__isset {
  _SennaService_senna_all_presult__isset() : success(false) {}
  bool success :1;
} _SennaService_senna_all_presult__isset;

class SennaService_senna_all_presult {
 public:

  static const char* ascii_fingerprint; // = "9A73381FEFD6B67F432E717102246330";
  static const uint8_t binary_fingerprint[16]; // = {0x9A,0x73,0x38,0x1F,0xEF,0xD6,0xB6,0x7F,0x43,0x2E,0x71,0x71,0x02,0x24,0x63,0x30};


  virtual ~SennaService_senna_all_presult() throw();
  std::string* success;

  _SennaService_senna_all_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

  friend std::ostream& operator<<(std::ostream& out, const SennaService_senna_all_presult& obj);
};

class SennaServiceClient : virtual public SennaServiceIf {
 public:
  SennaServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SennaServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void senna_all(std::string& _return, const std::string& inputs);
  void send_senna_all(const std::string& inputs);
  void recv_senna_all(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SennaServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<SennaServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SennaServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_senna_all(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SennaServiceProcessor(boost::shared_ptr<SennaServiceIf> iface) :
    iface_(iface) {
    processMap_["senna_all"] = &SennaServiceProcessor::process_senna_all;
  }

  virtual ~SennaServiceProcessor() {}
};

class SennaServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SennaServiceProcessorFactory(const ::boost::shared_ptr< SennaServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SennaServiceIfFactory > handlerFactory_;
};

class SennaServiceMultiface : virtual public SennaServiceIf {
 public:
  SennaServiceMultiface(std::vector<boost::shared_ptr<SennaServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SennaServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SennaServiceIf> > ifaces_;
  SennaServiceMultiface() {}
  void add(boost::shared_ptr<SennaServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void senna_all(std::string& _return, const std::string& inputs) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->senna_all(_return, inputs);
    }
    ifaces_[i]->senna_all(_return, inputs);
    return;
  }

};



#endif