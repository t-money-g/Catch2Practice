//
// Created by tyoun on 11/7/2021.
//
// https://www.boost.org/doc/libs/1_77_0/doc/html/property_tree/tutorial.html

#include <catch2/catch.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>


/* this tutorial uses XML, you can use any supported format (such as INI or JSON).
 * saved in build_dir/debug_settings.xml
<debug>
    <filename>debug.log</filename>
    <modules>
        <module>Finance</module>
        <module>Admin</module>
        <module>HR</module>
    </modules>
    <level>2</level>
</debug>
*/


namespace pt = boost::property_tree;
// or more like using ....


// store the logging configuration in the program we create a debug_settings structure:
struct debug_settings
{
    std::string m_file;             // log filename
    int m_level;                    // debug level
    std::set<std::string> m_modules;    // modules where logging is enabled
    void load(const std::string &filename);
    void save(const std::string &filename);
};

void debug_settings::load(const std::string &filename)
{
    // Create empty property tree object
    pt::ptree tree;

    // Parse the XML into the property tree.
    pt::read_xml(filename, tree);

    // Use the throwing version of get to find the debug filename.
    // if the path cannot be resolved, an exception is thrown .
    m_file = tree.get<std::string>("debug.filename");

    // use the default value version of get to find the debug level.
    m_level = tree.get("debug.level", 0);

    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("debug.modules"))
    {
        // the data function is used to access the data stored in a node.
        m_modules.insert(v.second.data());
    }
}

void debug_settings::save(const std::string &filename)
{
    // create an empty property tree object
    pt::ptree tree;

    // put the simple values into the tree. the integer is automatically
    // converted to a string. Note that the "debug" node is automatically
    // created if it doesn't exit .
    tree.put("debug.filename", m_file);
    tree.put("debug.level", m_level);

    // Add all the modules. Unlike pub, which overwrites existing nodes, add
    // adds a new node at a the lowest level, so the "modules" node will have
    // multiple "module" children.
    BOOST_FOREACH(const std::string &name, m_modules)
        tree.add("debug.modules.module", name);

    // write property tree to XML file
    pt::write_xml(filename, tree);
}


TEST_CASE("debug settings test with property tree")
{
    try
    {
        debug_settings ds;
        ds.load("debug_settings.xml");
        ds.save("debug_settings_out.xml");
        std::cout << "Success\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }
}