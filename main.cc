// hello.cc
#include <node.h>
#include <regex>
#include <string>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Boolean;
using std::string;
using std::regex;
using std::regex_match;

void matchRegex(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  String::Utf8Value s(args[0]);
  string str(*s);
  regex re("\\{\\w*\\}");
  Local<Boolean> b;

  if (regex_match(str, regex(re))) { b = Boolean::New(isolate, true); }
  else { b = Boolean::New(isolate, false); }
  args.GetReturnValue().Set(b);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "regex_matching", matchRegex);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo
