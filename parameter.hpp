#ifndef _PARAMETER_HPP_
#define _PARAMETER_HPP_

#include <opencv2/core/persistence.hpp>
#include <string>
#include <iostream>

#define ADD_PARAM(type, name, default_val) \
    public:     \
    static type name() { return GetInstance().c##name; } \
    private:    \
        bool LOAD_##name(cv::FileStorage &fs) {  \
           if (fs[#name].empty()) \
                return true; \
           fs[#name] >> c##name; \
           return false; }  \
        void SAVE_##name(cv::FileStorage &fs) {  \
           fs << #name << c##name;  }   \
        type c##name = default_val
           

namespace movslam {

// useage:
// 1. set file path somewhere before getting any parameters by
//      Parameter::SetFile("/somewhere");
// 2. get parameter hello by
//      Parameter::HELLO();
// 3. add new parameter:
//      put ADD_PARAM(int, hello, 10); at position 1
//      put LOAD_hello(fs); at position 2
//      put SAVE_hello(fs); at position 3
//      take care of the semicolon

class Parameter
{
public:
    Parameter(const Parameter &) = delete;
    void operator=(const Parameter &) = delete;
    static Parameter &GetInstance(const std::string &config = "")
    {
        static Parameter instance(config);
        return instance;
    }
    static void SetFile(const std::string &config)
    {
        GetInstance(config);
    }

    // position 1.
    ADD_PARAM(double, hello, 1.2);
    ADD_PARAM(int, test, 100);

private:
    Parameter();
    Parameter(const std::string &config);
};

Parameter::Parameter(const std::string &config)
{
    std::cout << "instantiation with config: " << config << std::endl;
    cv::FileStorage fs(config, cv::FileStorage::READ);
    bool has_new = false;
    if (fs.isOpened()) {
        // position 2.
        has_new |= LOAD_hello(fs);
        has_new |= LOAD_test(fs);
    } else {
        has_new = true;
    }
    fs.release();
    if (has_new) {
        fs.open(config, cv::FileStorage::WRITE);
        // position 3.
        SAVE_hello(fs);
        SAVE_test(fs);
        fs.release();
    }
}

}   // end of namespace movslam
#endif
