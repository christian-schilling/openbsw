// Copyright 2024 Accenture.

#pragma once

#include "logger/Config.h"
#include "logger/ConsoleEntryFormatter.h"
#include "logger/DefaultLoggerTime.h"

#include <logger/ConsoleEntryOutput.h>
#include <util/logger/IComponentMapping.h>
#include <util/logger/ILoggerOutput.h>

#include <estd/functional.h>

namespace logger
{
class LoggerComposition
{
public:
    using ConfigStart = ::estd::function<void(::util::logger::ILoggerOutput&)>;
    using ConfigStop  = ::estd::function<void()>;

    explicit LoggerComposition(
        ::util::logger::IComponentMapping& componentMapping, char const* name);

    void start(ConfigStart const& configStart);
    void run();
    void stop(ConfigStop const& configStop);

private:
    DefaultLoggerTime<> _loggerTime;

    ConsoleEntryFormatter<
        BufferedLoggerOutputType::EntryIndexType,
        BufferedLoggerOutputType::TimestampType>
        _loggerFormatter;

    ConsoleEntryOutput<
        BufferedLoggerOutputType::EntryIndexType,
        BufferedLoggerOutputType::TimestampType>
        _consoleLoggerOutput;

    BufferedLoggerOutputType _bufferedLoggerOutput;
    BufferedLoggerOutputType::EntryRefType _entryRef;
};

} // namespace logger
