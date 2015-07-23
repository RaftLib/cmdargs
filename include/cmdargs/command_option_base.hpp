/**
 * command_option_base.hpp - 
 * @author: Jonathan Beard
 * @version: Tue May 21 13:56:51 2013
 */
#ifndef _COMMAND_OPTION_BASE_HPP_
#define _COMMAND_OPTION_BASE_HPP_  1

#include <string>

class OptionBase{
public:
   OptionBase( const std::string flag,
               const std::string description,
               bool  Mandatory = false,
               bool  isHelp = false );

   virtual ~OptionBase();


   virtual bool setValue( const char *value ) = 0;
   virtual std::string toString() = 0;
   virtual std::string getValue() = 0;
   /** 
    * Returns true if the value has been set, useful for mandatory
    * arguments
    * @return bool
    */
   bool is_set();
   
   bool is_mandatory();
   bool is_help();
   std::string& get_flag();
   std::string& get_description();

protected:
   std::string toString( const std::string defaultValue );
   bool        set;

private:
   std::string flag;
   std::string description;
   bool        help;
   bool        mandatory;
};
#endif /* END _COMMAND_OPTION_BASE_HPP_ */
