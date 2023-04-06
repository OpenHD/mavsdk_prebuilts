// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/log_files/log_files.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mavsdk/plugin_base.h"

namespace mavsdk {

class System;
class LogFilesImpl;

/**
 * @brief Allow to download log files from the vehicle after a flight is complete.
 * For log streaming during flight check the logging plugin.
 */
class LogFiles : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto log_files = LogFiles(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit LogFiles(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto log_files = LogFiles(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit LogFiles(std::shared_ptr<System> system); // new

    /**
     * @brief Destructor (internal use only).
     */
    ~LogFiles() override;

    /**
     * @brief Progress data coming when downloading a log file.
     */
    struct ProgressData {
        float progress{float(NAN)}; /**< @brief Progress from 0 to 1 */
    };

    /**
     * @brief Equal operator to compare two `LogFiles::ProgressData` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const LogFiles::ProgressData& lhs, const LogFiles::ProgressData& rhs);

    /**
     * @brief Stream operator to print information about a `LogFiles::ProgressData`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, LogFiles::ProgressData const& progress_data);

    /**
     * @brief Log file entry type.
     */
    struct Entry {
        uint32_t id{}; /**< @brief ID of the log file, to specify a file to be downloaded */
        std::string date{}; /**< @brief Date of the log file in UTC in ISO 8601 format
                               "yyyy-mm-ddThh:mm:ssZ" */
        uint32_t size_bytes{}; /**< @brief Size of file in bytes */
    };

    /**
     * @brief Equal operator to compare two `LogFiles::Entry` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const LogFiles::Entry& lhs, const LogFiles::Entry& rhs);

    /**
     * @brief Stream operator to print information about a `LogFiles::Entry`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, LogFiles::Entry const& entry);

    /**
     * @brief Possible results returned for calibration commands
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        Next, /**< @brief Progress update. */
        NoLogfiles, /**< @brief No log files found. */
        Timeout, /**< @brief A timeout happened. */
        InvalidArgument, /**< @brief Invalid argument. */
        FileOpenFailed, /**< @brief File open failed. */
        NoSystem, /**< @brief No system is connected. */
    };

    /**
     * @brief Stream operator to print information about a `LogFiles::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, LogFiles::Result const& result);

    /**
     * @brief Callback type for asynchronous LogFiles calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Callback type for get_entries_async.
     */
    using GetEntriesCallback = std::function<void(Result, std::vector<Entry>)>;

    /**
     * @brief Get List of log files.
     *
     * This function is non-blocking. See 'get_entries' for the blocking counterpart.
     */
    void get_entries_async(const GetEntriesCallback callback);

    /**
     * @brief Get List of log files.
     *
     * This function is blocking. See 'get_entries_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, std::vector<LogFiles::Entry>> get_entries() const;

    /**
     * @brief Callback type for download_log_file_async.
     */

    using DownloadLogFileCallback = std::function<void(Result, ProgressData)>;

    /**
     * @brief Download log file.
     */
    void download_log_file_async(Entry entry, std::string path, DownloadLogFileCallback callback);

    /**
     * @brief Download log file synchronously.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    std::pair<Result, LogFiles::ProgressData>
    download_log_file(Entry entry, std::string path) const;

    /**
     * @brief Erase all log files.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result erase_all_log_files() const;

    /**
     * @brief Copy constructor.
     */
    LogFiles(const LogFiles& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const LogFiles& operator=(const LogFiles&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<LogFilesImpl> _impl;
};

} // namespace mavsdk