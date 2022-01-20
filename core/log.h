//
// Created by gilmar on 1/19/22.
//

#ifndef PHANTOMVK_LOG_H
#define PHANTOMVK_LOG_H

#include <fmt/format.h>
#include <fmt/color.h>
#include <fmt/chrono.h>

namespace ph {
    class Log {
    public:

        template<typename... Args>
        static void core_fatal(std::string_view format, const Args &... args) {
            get()->fatal("core", format, args...);
        }

        template<typename... Args>
        static void core_error(std::string_view format, const Args &... args) {
            get()->error("core", format, args...);
        }

        template<typename... Args>
        static void core_warning(std::string_view format, const Args &... args) {
            get()->warning("core", format, args...);
        }

        template<typename... Args>
        static void core_info(std::string_view format, const Args &... args) {
            get()->info("core", format, args...);
        }

        template<typename... Args>
        static void core_trace(std::string_view format, const Args &... args) {
            get()->trace("core", format, args...);
        }

        template<typename... Args>
        static void app_fatal(std::string_view format, const Args &... args) {
            get()->fatal("app", format, args...);
        }

        template<typename... Args>
        static void app_error(std::string_view format, const Args &... args) {
            get()->error("app", format, args...);
        }

        template<typename... Args>
        static void app_warning(std::string_view format, const Args &... args) {
            get()->warning("app", format, args...);
        }

        template<typename... Args>
        static void app_info(std::string_view format, const Args &... args) {
            get()->info("app", format, args...);
        }

        template<typename... Args>
        static void app_trace(std::string_view format, const Args &... args) {
            get()->trace("app", format, args...);
        }

        static Log *get() {
            static Log *instance = new Log();

            return instance;
        }

        ~Log() = default;

    private:
        Log() = default;


        template<typename... Args>
        inline void fatal(const char *level, std::string_view format, const Args &... args) {
            fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::red),
                       fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] [trace]: {}\n", std::chrono::system_clock::now(), level, fmt::format(format, args...)));
        }

        template<typename... Args>
        inline void error(const char *level, std::string_view format, const Args &... args) {
            fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::orange),
                       fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] [trace]: {}\n", std::chrono::system_clock::now(), level, fmt::format(format, args...)));
        }

        template<typename... Args>
        inline void warning(const char *level, std::string_view format, const Args &... args) {
            fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::yellow),
                       fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] [trace]: {}\n", std::chrono::system_clock::now(), level, fmt::format(format, args...)));
        }

        template<typename... Args>
        inline void info(const char *level, std::string_view format, const Args &... args) {
            fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::lime_green),
                       fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] [trace]: {}\n", std::chrono::system_clock::now(), level, fmt::format(format, args...)));
        }

        template<typename... Args>
        inline void trace(const char *level, std::string_view format, const Args &... args) {
            fmt::print(fmt::emphasis::bold | fmt::fg(fmt::color::sky_blue),
                       fmt::format("[{:%Y-%m-%d %H:%M:%S}] [{}] [trace]: {}\n", std::chrono::system_clock::now(), level, fmt::format(format, args...)));
        }
    };

} //namespace ph

#endif //PHANTOMVK_LOG_H
