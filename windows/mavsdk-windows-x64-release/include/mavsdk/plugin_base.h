#pragma once

namespace mavsdk {

/**
 * @brief Creates an overloaded callable object from multiple other callables
 *
 * This template class allows to combine multiple callable objects into one overloaded callable
 * object, that can handle different types of parameters. For example:
 *
 * overloaded {
 *     [](auto value) { LogErr() << "Got an unexpected type"; },
 *     [](uint32_t value) { LogDebug() << "Got an expected type"; }
 * }((uint32_t) 100);
 *
 * This is especially useful for creating callback functions to handle different parameter types
 */
template<class... Ts> struct overloaded : Ts... {
    using Ts::operator()...;
};

/**
 * @brief Template deduction helper for `overloaded`
 */
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

/**
 * @brief Base class for every plugin.
 */
class PluginBase {
public:
    /**
     * @brief Default Constructor.
     */
    PluginBase() = default;

    /**
     * @brief Default Destructor.
     */
    virtual ~PluginBase() = default;

    /**
     * @brief Copy constructor (object is not copyable).
     */
    PluginBase(const PluginBase&) = delete;

    /**
     * @brief Assign operator (object is not copyable).
     */
    const PluginBase& operator=(const PluginBase&) = delete;
};

} // namespace mavsdk
