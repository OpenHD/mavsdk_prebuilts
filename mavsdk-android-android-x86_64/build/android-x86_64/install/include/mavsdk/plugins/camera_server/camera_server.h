// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/camera_server/camera_server.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "mavsdk/server_plugin_base.h"

namespace mavsdk {

class ServerComponent;
class CameraServerImpl;

/**
 * @brief Provides handling of camera trigger commands.
 */
class CameraServer : public ServerPluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a ServerComponent instance.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto camera_server = CameraServer(server_component);
     *     ```
     *
     * @param server_component The ServerComponent instance associated with this server plugin.
     */
    explicit CameraServer(std::shared_ptr<ServerComponent> server_component);

    /**
     * @brief Destructor (internal use only).
     */
    ~CameraServer() override;

    /**
     * @brief Possible results when taking a photo.
     */
    enum class TakePhotoFeedback {
        Unknown, /**< @brief Unknown. */
        Ok, /**< @brief Ok. */
        Busy, /**< @brief Busy. */
        Failed, /**< @brief Failed. */
    };

    /**
     * @brief Stream operator to print information about a `CameraServer::TakePhotoFeedback`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::TakePhotoFeedback const& take_photo_feedback);

    /**
     * @brief Type to represent a camera information.
     */
    struct Information {
        std::string vendor_name{}; /**< @brief Name of the camera vendor */
        std::string model_name{}; /**< @brief Name of the camera model */
        std::string firmware_version{}; /**< @brief Camera firmware version in
                                           major[.minor[.patch[.dev]]] format */
        float focal_length_mm{}; /**< @brief Focal length */
        float horizontal_sensor_size_mm{}; /**< @brief Horizontal sensor size */
        float vertical_sensor_size_mm{}; /**< @brief Vertical sensor size */
        uint32_t horizontal_resolution_px{}; /**< @brief Horizontal image resolution in pixels */
        uint32_t vertical_resolution_px{}; /**< @brief Vertical image resolution in pixels */
        uint32_t lens_id{}; /**< @brief Lens ID */
        uint32_t
            definition_file_version{}; /**< @brief Camera definition file version (iteration) */
        std::string
            definition_file_uri{}; /**< @brief Camera definition URI (http or mavlink ftp) */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Information` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::Information& lhs, const CameraServer::Information& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Information`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::Information const& information);

    /**
     * @brief Position type in global coordinates.
     */
    struct Position {
        double latitude_deg{}; /**< @brief Latitude in degrees (range: -90 to +90) */
        double longitude_deg{}; /**< @brief Longitude in degrees (range: -180 to +180) */
        float absolute_altitude_m{}; /**< @brief Altitude AMSL (above mean sea level) in metres */
        float relative_altitude_m{}; /**< @brief Altitude relative to takeoff altitude in metres */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Position` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const CameraServer::Position& lhs, const CameraServer::Position& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Position`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Position const& position);

    /**
     * @brief Quaternion type.
     *
     * All rotations and axis systems follow the right-hand rule.
     * The Hamilton quaternion product definition is used.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     * The quaternion could also be written as w + xi + yj + zk.
     *
     * For more info see: https://en.wikipedia.org/wiki/Quaternion
     */
    struct Quaternion {
        float w{}; /**< @brief Quaternion entry 0, also denoted as a */
        float x{}; /**< @brief Quaternion entry 1, also denoted as b */
        float y{}; /**< @brief Quaternion entry 2, also denoted as c */
        float z{}; /**< @brief Quaternion entry 3, also denoted as d */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::Quaternion` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::Quaternion& lhs, const CameraServer::Quaternion& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::Quaternion`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Quaternion const& quaternion);

    /**
     * @brief Information about a picture just captured.
     */
    struct CaptureInfo {
        Position position{}; /**< @brief Location where the picture was taken */
        Quaternion attitude_quaternion{}; /**< @brief Attitude of the camera when the picture was
                                             taken (quaternion) */
        uint64_t time_utc_us{}; /**< @brief Timestamp in UTC (since UNIX epoch) in microseconds */
        bool is_success{}; /**< @brief True if the capture was successful */
        int32_t index{}; /**< @brief Index from TakePhotoResponse */
        std::string file_url{}; /**< @brief Download URL of this image */
    };

    /**
     * @brief Equal operator to compare two `CameraServer::CaptureInfo` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool
    operator==(const CameraServer::CaptureInfo& lhs, const CameraServer::CaptureInfo& rhs);

    /**
     * @brief Stream operator to print information about a `CameraServer::CaptureInfo`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, CameraServer::CaptureInfo const& capture_info);

    /**
     * @brief Possible results returned for action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Command executed successfully. */
        InProgress, /**< @brief Command in progress. */
        Busy, /**< @brief Camera is busy and rejected command. */
        Denied, /**< @brief Camera denied the command. */
        Error, /**< @brief An error has occurred while executing the command. */
        Timeout, /**< @brief Command timed out. */
        WrongArgument, /**< @brief Command has wrong argument(s). */
        NoSystem, /**< @brief No system connected. */
    };

    /**
     * @brief Stream operator to print information about a `CameraServer::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, CameraServer::Result const& result);

    /**
     * @brief Callback type for asynchronous CameraServer calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Sets the camera information. This must be called as soon as the camera server is
     * created.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_information(Information information) const;

    /**
     * @brief Sets image capture in progress status flags. This should be set to true when the
     * camera is busy taking a photo and false when it is done.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result set_in_progress(bool in_progress) const;

    /**
     * @brief Callback type for subscribe_take_photo.
     */

    using TakePhotoCallback = std::function<void(int32_t)>;

    /**
     * @brief Subscribe to image capture requests. Each request received should respond to using
     * RespondTakePhoto.
     */
    void subscribe_take_photo(TakePhotoCallback callback);

    /**
     * @brief Respond to an image capture request from SubscribeTakePhoto.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result
    respond_take_photo(TakePhotoFeedback take_photo_feedback, CaptureInfo capture_info) const;

    /**
     * @brief Copy constructor.
     */
    CameraServer(const CameraServer& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const CameraServer& operator=(const CameraServer&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<CameraServerImpl> _impl;
};

} // namespace mavsdk