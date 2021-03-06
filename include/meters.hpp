#ifndef METERS_HPP
#define METERS_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include "iosifovitch.hpp"
// #include "edlib.h"

 const std::unordered_map<std::string,  std::string> METERS{
      {"1101010110101011010101101010",									"مفاعیلن مفاعیلن مفاعیلن مفاعیلن"},
    {"11010101101010110101011010",										"مفاعیلن مفاعیلن مفاعیلن فعولن"},
    {"110110110110110110110110",										"مفاعلن مفاعلن مفاعلن مفاعلن"},
    {"101101101010101101101010",										"فاعلن مفاعیلن فاعلن مفاعیلن"},
   //  {"1011011010101101101101010",										"فاعلن مفاعیلان فاعلن مفاعیلن"},
    {"11011011010101101101101010",										"مفاعلن مفاعلن مفاعلن مفاعیلن"},
    {"101011101011101011101010",										"مفعول مفاعیل مفاعیل مفاعیلن"},
    {"101011101010101011101010",										"مفعول مفاعیلن مفعول مفاعیلن"},
   //  {"1010111010101101011101010",										"مفعول مفاعیلان مفعول مفاعیلان"},
    {"1010111010111010111010",											"مفعول مفاعیل مفاعیل فعولن"},
    {"1010101010111010111010",											"مفعولن مفعول مفاعیل فعولن"},
    {"1010111010101010111010",											"مفعول مفاعیلن مفعول فعولن"},
    {"1010111010111010101010",											"مفعول مفاعیل مفاعیلن فعلن"},
    {"110101011010101101010",											"مفاعیلن مفاعیلن مفاعیلن"},
    {"1101010110101011010",												"مفاعیلن مفاعیلن فعولن"},
    {"1010111011011010",													"مفعول مفاعلن فعولن"},
    {"1010101011011010",													"مفعولن فاعلن فعولن"},
    {"1011011011010110110110",											"فاعلن مفاعلن فاعلن مفاعلن"},
   //  {"10110110110110110110110",											"فاعلن مفاعلان فاعلن مفاعلن"},
    {"110101011010",														"مفاعیلن فعولن"},
    {"110101011010110101011010",										"مفاعیلن فعولن مفاعیلن فعولن"},
    {"1010110101011010101101010110",									"مستفعلن مستفعلن مستفعلن مستفعلن"},
    {"101110101110101110101110",										"مفتَعِلن مفتَعِلن مفتَعِلن مفتَعِلن"},
    {"101110110110101110110110",										"مفتَعِلن مفاعلن مفتَعِلن مفاعلن"},
   //  {"1011101101101101110110110",										"مفتَعِلن مفاعلان مفتَعِلن مفاعلن"},
   // {"110110101110110110101110",										"مفاعلن مفتَعِلن مفاعلن مفتَعِلن"},
    {"101011010101101010110",											"مستفعلن مستفعلن مستفعلن"},
    {"101110101110101110",												"مفتَعِلن مفتَعِلن مفتَعِلن"},
    {"1011010101101010110101011010",									" فاعلاتن فاعلاتن فاعلاتن فاعلاتن"},
    {"10110101011010101101010110",										"فاعلاتن فاعلاتن فاعلاتن فاعلن"},
    {"101101010110101011010101101",										"فاعلاتن فاعلاتن فاعلاتن فاعلات"},
    {"10110101110101110101110",											"فاعلاتن فعِلاتن فعِلاتن فعِلن"},
    {"1110101110101110101110",											"فعِلاتن فعِلاتن فعِلاتن فعِلن"},
    {"11101011101011101011101",											"فعِلاتن فعِلاتن فعِلاتن فعِلات"},
    {"10110101110101110101010",											"فاعلاتن فعِلاتن فعِلاتن فعلن"},
    {"1110101110101110101010",											"فعِلاتن فعِلاتن فعِلاتن فعلن"},
    {"111011011010111011011010",										"فعِلات فاعلاتن فعِلات فاعلاتن"},
    {"111010111010111010111010",										"فعِلاتن فعِلاتن فعِلاتن فعِلاتن"},
    {"101101010110101011010",											"فاعلاتن فاعلاتن فاعلاتن"},
    {"1011010101101010110",												"فاعلاتن فاعلاتن فاعلن"},
    {"10110101110101110",												"فاعلاتن فعِلاتن فعِلن"},
    {"10110101110101010",												"فاعلاتن فعِلاتن فعلن"},
    {"1110101110101110",													"فعِلاتن فعِلاتن فعِلن"},
    {"1110101110101010",													"فعِلاتن فعِلاتن فعِلن"},
    {"111010111010111010",												"فعِلاتن  فعِلاتن فعِلاتن"},
    {"11010110101101011010",											"فعولن فعولن فعولن فعولن"},
    {"1101011010110101101011010110101101011010",					"فعولن فعولن فعولن فعولن فعولن فعولن فعولن فعولن"},
    {"110101101011010110",												"فعولن فعولن فعولن فعَل"},
    {"1011101110111010",												"فاع فعول فعول فعولن"},
    {"10111011101110",													"فاع فعول فعول فعَل"},
    {"101110111011101110111011101110",								"فاع فعول فعول فعول فعول فعول فعول فعَل"},
    {"10111011101110111011101110111010",							"فاع فعول فعول فعول فعول فعول فعول فعولن"},
    {"110101101011010",													"فعولن فعولن فعولن"},
    {"1101011010110",													"فعولن فعولن فعَل"},
    {"101011010101011010",												"فعلن فعولن فعلن فعولن"},
    {"10110101101011010110",											"فاعلن فاعلن فاعلن فاعلن"},
    {"1110111011101110",												"فعِلن فعِلن فعِلن فعِلن"},
    {"11101110111011101110111011101110",							"فعِلن فعِلن فعِلن فعِلن فعِلن فعِلن فعِلن فعِلن"},
   // {"1011010110101101110",												"فاعلن فاعلن فاعلن فعِلن"},
    {"101101011010110",													"فاعلن فاعلن فاعلن"},
    {"1011011010110110",												"فاعلن فعَل فاعلن فعَل"},
    {"1110110111011011101101110110",									"متفاعلن متفاعلن متفاعلن متفاعلن"},
    {"111011011101101110110",											"متفاعلن متفاعلن متفاعلن"},
    {"1101110110111011011101101110",									"مفاعلتن مفاعلتن مفاعلتن مفاعلتن"},
    {"110111011011101101110",											"مفاعلتن مفاعلتن مفاعلتن"},
    {"1101110110111011010",												"مفاعلتن مفاعلتن فعولن"},
    //{"1101010/1011010/1101010/1011010",									"مفاعیلن فاعلاتن مفاعیلن فاعلاتن"},//
   // {"110101/101101/110101/10110",											"مضارع مثمن مکفوف محذوف"},//

    {"101011011010101011011010",										"مفعول فاعلاتن مفعول فاعلاتن"},
   //  {"1010110110101101011011010",										"مفعول فاعلاتان مفعول فاعلاتن"},
    {"1010110110111010110110",											"مفعول فاعلات مفاعیل فاعلن"},
  //  {"1010110110101010110110",											"مفعول فاعلاتن مفعول فاعلن"},
    //{"10101/101101/1101010",												"مضارع مسدس اخرب مکفوف"},//
    //{"1010110/1011010/1010110/1011010",									"مستفعلن فاعلاتن مستفعلن فاعلاتن"},//
    {"110110111010110110111010",										"مفاعلن فعِلاتن مفاعلن فعِلاتن"},
   // {"110110101010110110111010",										"مفاعلن مفعولن مفاعلن فعِلاتن"},
   // {"110110/111010/110110/101010",										"مفاعلن فعِلاتن مفاعلن مفعولن"},
 //   {"110110/101010/110110/101010",										"مجتث مثمن مخبون"},
    {"1101101110101101101110",											"مفاعلن فعِلاتن مفاعلن فعِلن"},
 //   {"110110/101010/110110/1110",											"مجتث مثمن مخبون محذوف"},
    {"1101101110101101101010",											"مفاعلن فعِلاتن مفاعلن فعلن"},
    //{"110110/101010/110110/1010",											"مجتث مثمن مخبون محذوف مسکن"},//
    {"110110/111010/110110",												"مفاعلن فعِلاتن مفاعلن"},
    //{"110110/101010/110110",												"مجتث مسدس مخبون"},
    //{"1010110/1010101/1010110/1010101",									"مستفعلن مفعولاتُ مستفعلان مفعولاتُ"},

    {"1011101011010111010110",											"مفتعِلن فاعلن مفتعِلن فاعلن"},
    {"10111010110110111010110",											"مفتعِلن فاعلات مفتعِلن فاعلن"},
    {"10111010110110111010",											"مفتعِلن فاعلات مفتعِلن فع"},
    {"10111010110101110",												"مفتعِلن فاعلن مفتعِلن"},
 //   {"1010101/1010110/1010101/1010110",									"مفعولاتُ مستفعلن مفتعولات مستفعلن"},
    {"101101101110101101101110",										"فاعلات مفتعِلن فاعلات مفتعِلن"},
   //  {"1011011011101101101101110",										"فاعلات مفتعِلان فاعلات مفتعِلن"},
   // {"1010110/1010110/1010101",											"مستفعلن مستفعلن مفعولات"},
    {"10111010111010110",												"مفتعِلن مفتعِلن فاعلن"},
 //   {"1010110/1010110/11010",												"مستفعلن مستفعلن فعولن"},
   // {"1011010/1010110/1011010/1010110",									"فاعلاتن مستفعلن فاعلاتن مستفعلن"},
  //  {"1011010/1010110/1011010",											"فاعلاتن مستفعلن فاعلاتن"},
 //   {"111010/110110/111010",												"خفیف مسدس مخبون"},
    {"10110101101101010",												"فاعلاتن مفاعلن فعلن"},
    {"1110101101101010",													"فعِلاتن مفاعلن فعلن"},
   {"101101011011010",													"فاعلاتن مفاعلن فع"},
    {"11101011011010",													"فعِلاتن مفاعلن فع"},
    {"10110101101101110",												"فاعلاتن مفاعلن فعِلن"},
    {"1110101101101110",													"فعِلاتن مفاعلن فعِلن"},
   // {"1101010/11010/1101010",												"مفاعیلن فعولن مفاعیلن"},
    {"11010110101011010110110",											"فعولن مفاعیلن فعولن مفاعیلن"},
  //  {"11010/110110/11010/110110",											"طویل مثمن مقبوض"},
    {"101101010110101101010110",										"فاعلاتن فاعلن فاعلاتن فاعلن"},
 //   {"1011010101101101101010110",										"فاعلاتن فاعلان فاعلاتن فاعلن"},
    {"11101011101110101110",											"فعِلاتن فعِلن فعِلاتن فعِلن"},
   //  {"111010111011110101010",											"فعِلاتن فعِلان فعِلاتن فعلن"},
    {"11101010101110101110",											"فعلاتن فعلن فعلاتن فعلن"},
   //  {"111010111011110101010",											"فعِلاتن فعِلان فعِلاتن فعلن"},
    //{"101010/1110/111010/1110",											"مدید مثمن مخبون"},
    //{"111010/1110/101010/1110",											"مدید مثمن مخبون"},
    //{"111010/1110/111010/1010",											"مدید مثمن مخبون"},
    //{"1011010111010110101110",											"فاعلاتن فعِلن فاعلاتن فعِلن"},
    //{"1010110/10110/1010110/10110",										"مستفعلن فاعلن مستفعلن فاعلن"},
    //{"110110/1110/110110/1110",											"بسیط مثمن مخبون"},
    //{"1101010/1101010/1011010",											"مفاعیلن مفاعیلن فاعلاتن"},
   // {"10101/110101/1011010",												"قریب مسدس اخرب مکفوف"},
    //{"1011010/1011010/1010110",											"فاعلاتن فاعلاتن مستفعلن"},
   // {"111010/111010/110110",												"جدید مسدس مخبون"},
    //{"1011010/1101010/1101010",											"فاعلاتن مفاعیلن مفاعیلن"},
    {"10110111010111010",												"فاعلات مفاعیل فعولن"},
    {"11011010110110101101101011011010",								"فعول فعلن فعول فعلن فعول فعلن فعول فعلن"},
    {"101101101010",														"فاعلن مفاعیلن"},
    {"10110110110",														"فاعلن مفاعلن"},
    {"11010101101010",													"مفاعیلن مفاعیلن"},
    {"110110110110110110110",											"مفاعلن مفاعلن مفاعلن فعَل"},
    {"1011010111010111010",												"فاعلاتن فعِلاتن فعِلاتن"},
    {"10110101011010",													"فاعلاتن فاعلاتن"},
    {"101101010110",														"فاعلاتن فاعلن"},
    {"1101011010",														"فعولن فعولن"},
    {"11101101110110",													"متفاعلن متفاعلن"},
 //   {"11010/1101010",														"طویل مربع سالم"},
 //   {"1011010/10110",														"مدید مربع سالم"},
    {"11010101101010110101011010101101010110101011010101101010",	"مفاعیلن مفاعیلن مفاعیلن مفاعیلن مفاعیلن مفاعیلن مفاعیلن مفاعیلن"},
    {"1101101011011010",													"فعول فعلن فعول فعلن" },
    {"110110101101101011011010",													"فعول فعلن فعول فعلن فعول فعلن" }
};

 const std::unordered_map< std::string,  std::string> NAMES
{
    {"1101010110101011010101101010",									"ہزج مثمن سالم"},
    {"11010101101010110101011010",										"ہزج مثمن محذوف"},
    {"110110110110110110110110",										"ہزج مثمن مقبوض"},
    {"101101101010101101101010",										"ہزج مثمن اشتر"},
    {"1011011010101101101101010",										"ہزج مثمن اشتر مسبغ"},
    {"11011011010101101101101010",										"ہزج مثمن مقبوض سالم"},
    {"101011101011101011101010",										"ہزج مثمن اخرب مکفوف سالم"},
    {"101011101010101011101010",										"ہزج مثمن اخرب سالم"},
    {"1010111010101101011101010",										"ہزج مثمن اخرب سالم مسبغ"},
    {"1010111010111010111010",											"ہزج مثمن اخرب مکفوف محذوف"},
    {"1010101010111010111010",											"ہزج مثمن اخرب مکفوف محذوف"},
    {"1010111010101010111010",											"ہزج مثمن اخرب مکفوف محذوف"},
    {"1010111010111010101010",											"ہزج مثمن اخرب مکفوف محذوف"},
    {"110101011010101101010",											"ہزج مسدس سالم"},
    {"1101010110101011010",												"ہزج مسدس محذوف"},
    {"1010111011011010",													"ہزج مسدس اخرب مقبوض محذوف"},
    {"1010101011011010",													"ہزج مسدس اخرم اشتر محذوف"},
    {"1011011011010110110110",											"ہزج مربع اشتر مقبوض مضاعف"},
    {"110101011010",														"ہزج مربع محذوف"},
    {"110101011010110101011010",										"ہزج مربع محذوف مضاعف"},
    {"1010110101011010101101010110",									"رجز مثمن سالم"},
    {"101110101110101110101110",										"رجز مثمن مطوی"},
    {"101110110110101110110110",										"رجز مثمن مطوی مخبون"},
    {"1011101101101101110110110",										"رجز مثمن مطوی مخبون مذال"},
    {"110110101110110110101110",										"رجز مثمن مخبون مطوی"},
    {"101011010101101010110",											"رجز مسدس سالم"},
    {"101110101110101110",												"رجز مسدس مطوی"},
    {"1011010101101010110101011010",									"رمل مثمن سالم"},
    {"10110101011010101101010110",										"رمل مثمن محذوف"},
     {"101101010110101011010101101",										"رمل مثمن محذوف مسبغ"},
    {"10110101110101110101110",											"رمل مثمن سالم مخبون محذوف"},
    {"1110101110101110101110",											"رمل مثمن سالم مخبون محذوف"},
    {"10110101110101110101010",											"رمل مثمن مخبون محذوف مقطوع"},
    {"1110101110101110101010",											"رمل مثمن مخبون محذوف مقطوع"},
    {"11101011101011101011101",											"رمل مثمن مخبون محذوف مقطوع مسبغ"},
    {"111011011010111011011010",										"رمل مثمن مشکول"},
    {"101011011010101011011010",										"مضارع مثمن اخرب"},
    {"111010111010111010111010",										"رمل مثمن مخبون"},
    {"101101010110101011010",											"رمل مسدس سالم"},
    {"1011010101101010110",												"رمل مسدس محذوف"},
    {"10110101110101110",												"رمل مسدس مخبون محذوف"},
    {"10110101110101010",												"رمل مسدس مخبون محذوف مسکن"},
    {"1110101110101110",													"رمل مسدس مخبون محذوف"},
    {"1110101110101010",													"رمل مسدس مخبون محذوف مسکن"},
    {"111010111010111010",												"رمل مسدس مخبون"},
    {"11010110101101011010",											"متقارب مثمن سالم"},
    {"1101011010110101101011010110101101011010",					"متقارب مثمن سالم مضاعف"},
    {"110101101011010110",												"متقارب مثمن محذوف"},
    {"1011101110111010",												"متقارب مثمن اثرم مقبوض"},
    {"10111011101110",													"متقارب مثمن اثرم مقبوض محذوف"},
    {"101110111011101110111011101110",								"متقارب مثمن اثرم مقبوض مضاعف"},
    {"10111011101110111011101110111010",							"متقارب مثمن اثرم مقبوض محذوف مضاعف"},
    {"110101101011010",													"متقارب مسدس سالم"},
    {"1101011010110",													"متقارب مسدس محذوف"},
    {"101011010101011010",												"متقارب مربع اثلم سالم مضاعف"},
    {"10110101101011010110",											"متدارک مثمن سالم"},
    {"1110111011101110",												"متدارک مثمن مخبون"},
    {"11101110111011101110111011101110",							"متدارک مثمن مخبون مضاعف"},
    {"1011010110101101110",												"متدارک مثمن سالم مقطوع"},
    {"101101011010110",													"متدارک مسدس سالم"},
    {"1011011010110110",												"متدارک مربع مخلع مضاعف"},
    {"1110110111011011101101110110",									"کامل مثمن سالم"},
    {"111011011101101110110",											"کامل مسدس سالم"},
    {"1101110110111011011101101110",									"وافر مثمن سالم"},
    {"110111011011101101110",											"وافر مسدس سالم"},
    {"1101110110111011010",												"وافر مسدس مقطوف"},
    {"1101010101101011010101011010",									"مضارع مثمن سالم"},
    {"11010110110111010110110",											"مضارع مثمن مکفوف محذوف"},
    {"101011011010101011011010",										"مضارع مثمن اخرب"},
     {"1010110110101101011011010",										"مضارع مثمن اخرب مسبغ"},
    {"1010110110111010110110",											"مضارع مثمن اخرب مکفوف محذوف"},
    {"1010110110101010110110",											"مضارع مثمن اخرب محذوف"},
    {"101011011011101010",												"مضارع مسدس اخرب مکفوف"},
    {"1010110101101010101101011010",									"مجتث مثمن سالم"},
    {"110110111010110110111010",										"مجتث مثمن مخبون"},
    {"110110101010110110111010",										"مجتث مثمن مخبون"},
    {"110110111010110110101010",										"مجتث مثمن مخبون"},
    {"110110101010110110101010",										"مجتث مثمن مخبون"},
    {"1101101110101101101110",											"مجتث مثمن مخبون محذوف"},
    {"1101101010101101101110",											"مجتث مثمن مخبون محذوف"},
    {"1101101110101101101010",											"مجتث مثمن مخبون محذوف مسکن"},
    {"1101101010101101101010",											"مجتث مثمن مخبون محذوف مسکن"},
    {"110110111010110110",												"مجتث مسدس مخبون"},
    {"110110101010110110",												"مجتث مسدس مخبون"},
    {"1010110101010110101101010101",									"منسرح مثمن سالم"},
    {"1011101011010111010110",											"منسرح مثمن مطوی مکسوف"},
    {"10111010110110111010110",											"منسرح مثمن مطوی مکسوف مذال"},
    {"10111010110110111010",											"منسرح مثمن مطوی منحور"},
    {"10111010110101110",												"منسرح مسدس مطوی مکسوف"},
    {"1010101101011010101011010110",									"مقتضب مثمن سالم"},
    {"101101101110101101101110",										"مقتضب مثمن مطوی"},
    {"101011010101101010101",											"سریع مسدس سالم"},
    {"10111010111010110",												"سریع مسدس مطوی مکسوف"},
    {"1010110101011011010",												"سریع مسدس مخبون مکسوف"},
    {"1011010101011010110101010110",									"خفیف مثمن سالم"},
    {"101101010101101011010",											"خفیف مسدس سالم"},
    {"111010110110111010",												"خفیف مسدس مخبون"},
    {"10110101101101110",												"خفیف مسدس مخبون محذوف"},
    {"1110101101101110",													"خفیف مسدس مخبون محذوف"},
    {"10110101101101010",												"خفیف مسدس مخبون محذوف مقطوع"},
    {"1110101101101010",													"خفیف مسدس مخبون محذوف مقطوع"},
    {"101101011011010",													"خفیف مسدس سالم مخبون محجوف"},
    {"11101011011010",													"خفیف مسدس مخبون محجوف"},
    {"1101010110101101010",												"طویل مثمن سالم"},
    {"11010110101011010110110",											"طویل مثمن سالم مقبوض"},
    {"1101011011011010110110",											"طویل مثمن مقبوض"},
    {"101101010110101101010110",										"مدید مثمن سالم"},
    {"11101011101110101110",											"مدید مثمن مخبون"},
    {"11101010101110101110",											"مدید مثمن مخبون"},
    {"10101011101110101110",											"مدید مثمن مخبون"},
    {"11101011101010101110",											"مدید مثمن مخبون"},
    {"11101011101110101010",											"مدید مثمن مخبون"},
    {"1011010111010110101110",											"مدید مثمن سالم مخبون"},
    {"101011010110101011010110",										"بسیط مثمن سالم"},
    {"11011011101101101110",											"بسیط مثمن مخبون"},
    {"110101011010101011010",											"قریب مسدس سالم"},
    {"101011101011011010",												"قریب مسدس اخرب مکفوف"},
    {"101101010110101010110",											"جدید مسدس سالم"},
    {"111010111010110110",												"جدید مسدس مخبون"},
    {"101101011010101101010",											"مشاکل مسدس سالم"},
    {"10110111010111010",												"مشاکل مسدس مکفوف محذوف"},
    {"11011010110110101101101011011010",								"جمیل مثمن سالم"},
    {"101101101010",														"ہزج مربع اشتر"},
    {"10110110110",														"ہزج مربع اشتر مقبوض"},
    {"11010101101010",													"ہزج مربع سالم"},
    {"110110110110110110110",											"ہزج مثمن مقبوض مجبوب الاخر"},
    {"1011010111010111010",												"رمل مسدس مخبون"},
    {"11010101101010",													"ہزج مربع سالم"},
    {"10110101011010",													"رمل مربع سالم"},
    {"101101010110",														"رمل مربع محذوف"},
    {"1101011010",														"متقارب مربع سالم"},
    {"11101101110110",													"کامل مربع سالم"},
    {"110101101010",														"طویل مربع سالم"},
    {"101101010110",														"مدید مربع سالم"},
    {"11010101101010110101011010101101010110101011010101101010",	"ہزج مثمن سالم مضاعف"},
    {"1101101011011010",													"متقارب مثمن مقبوض اثلم" }
    // {"10101010101010101010101010101010" , "بحرِ زمزمہ"},
    // {"10101010101010101010101010101110" , "بحرِ زمزمہ"},
    // {"10101010101010101010101011101010" , "بحرِ زمزمہ"},
    // {"10101010101010101010101011101110" , "بحرِ زمزمہ"},
    // {"10101010101010101010111010101010" , "بحرِ زمزمہ"},
    // {"10101010101010101010111011101110" , "بحرِ زمزمہ"},
    // {"10101010101010101110101010101010" , "بحرِ زمزمہ"},
    // {"10101010101010101110111011101110" , "بحرِ زمزمہ"},
    // {"10101010101011101010101010101010" , "بحرِ زمزمہ"},
    // {"10101010101011101110111011101110" , "بحرِ زمزمہ"},
    // {"10101010111010101010101010101010" , "بحرِ زمزمہ"},
    // {"10101010111011101110111011101110" , "بحرِ زمزمہ"},
    // {"10101110101010101010101010101010" , "بحرِ زمزمہ"},
    // {"10101110111011101110111011101110" , "بحرِ زمزمہ"},
    // {"11101010101010101010101010101010" , "بحرِ زمزمہ"},
    // {"11101010101010101010101010101110" , "بحرِ زمزمہ"},
    // {"11101010101010101010101011101110" , "بحرِ زمزمہ"},
    // {"11101010101010101010111011101110" , "بحرِ زمزمہ"},
    // {"11101010101010101110111011101110" , "بحرِ زمزمہ"},
    // {"11101010101011101110111011101110" , "بحرِ زمزمہ"},
    // {"11101010111011101110111011101110" , "بحرِ زمزمہ"},
    // {"11101110101010101010101010101010" , "بحرِ زمزمہ"},
    // {"11101110101010101010101010101110" , "بحرِ زمزمہ"},
    // {"11101110101010101010101011101110" , "بحرِ زمزمہ"},
    // {"11101110101010101010111011101110" , "بحرِ زمزمہ"},
    // {"11101110101010101110111011101110" , "بحرِ زمزمہ"},
    // {"11101110101011101110111011101110" , "بحرِ زمزمہ"},
    // {"11101110111010101010101010101010" , "بحرِ زمزمہ"},
    // {"11101110111010101010101010101110" , "بحرِ زمزمہ"},
    // {"11101110111010101010101011101110" , "بحرِ زمزمہ"},
    // {"11101110111010101010111011101110" , "بحرِ زمزمہ"},
    // {"11101110111010101110111011101110" , "بحرِ زمزمہ"},
    // {"11101110111011101010101010101010" , "بحرِ زمزمہ"},
    // {"11101110111011101010101010101110" , "بحرِ زمزمہ"},
    // {"11101110111011101010101011101110" , "بحرِ زمزمہ"},
    // {"11101110111011101010111011101110" , "بحرِ زمزمہ"},
    // {"11101110111011101110101010101010" , "بحرِ زمزمہ"},
    // {"11101110111011101110101010101110" , "بحرِ زمزمہ"},
    // {"11101110111011101110101011101110" , "بحرِ زمزمہ"},
    // {"11101110111011101110111010101010" , "بحرِ زمزمہ"},
    // {"11101110111011101110111010101110" , "بحرِ زمزمہ"},
    // {"11101110111011101110111011101010" , "بحرِ زمزمہ"}
};

const std::vector<std::string> METERLIST{
    "1101010110101011010101101010",
	"11010101101010110101011010",
	"110110110110110110110110",
	"101101101010101101101010",
	// "1011011010101101101101010",
	// "11011011010101101101101010",
	// "101011101011101011101010",
	"101011101010101011101010",
	// "1010111010101101011101010",
	"1010111010111010111010",
	// "1010101010111010111010",
	"1010111010101010111010",
	// "1010111010111010101010",
	"110101011010101101010",
	"1101010110101011010",
	"1010111011011010",
	"1010101011011010",
	"1011011011010110110110",
	// "10110110110110110110110",
	"110101011010",
	// "110101011010110101011010",
	"1010110101011010101101010110",
	"101110101110101110101110",
	"101110110110101110110110",
	// "1011101101101101110110110",
	// "110110101110110110101110",
	"101011010101101010110",
	"101110101110101110",
	"1011010101101010110101011010",
	"10110101011010101101010110",
	//"101101010110101011010101101",
	"10110101110101110101110",
	"1110101110101110101110",
	//"11101011101011101011101",
	"10110101110101110101010",
	"1110101110101110101010",
	"111011011010111011011010",
	"111010111010111010111010",
	"101101010110101011010",
	"1011010101101010110",
	"10110101110101110",
	"10110101110101010",
	"1110101110101110",
	"1110101110101010",
	"111010111010111010",
	"11010110101101011010",
	"1101011010110101101011010110101101011010",
	"110101101011010110",
	// "1011101110111010",
	// "10111011101110",
	// "101110111011101110111011101110",
	// "10111011101110111011101110111010",
	"110101101011010",
	"1101011010110",
	"101011010101011010",
	"10110101101011010110",
	"1110111011101110",
	"11101110111011101110111011101110",
	// "1011010110101101110",
	"101101011010110",
	"1011011010110110",
	"1110110111011011101101110110",
	"111011011101101110110",
	// "1101110110111011011101101110",
	// "110111011011101101110",
	// "1101110110111011010",
	//"1101010/1011010/1101010/1011010",
	// "110101/101101/110101/10110",

	"101011011010101011011010",
	// "1010110110101101011011010",
	"1010110110111010110110",
	//  "1010110110101010110110",
	//"10101/101101/1101010",
	//"1010110/1011010/1010110/1011010",
	"110110111010110110111010",
	// "110110101010110110111010",
	// "110110/111010/110110/101010",
	//   "110110/101010/110110/101010",
	"1101101110101101101110",
	//   "110110/101010/110110/1110",
	"1101101110101101101010",
	//"110110/101010/110110/1010",
	// "110110/111010/110110",
	//"110110/101010/110110",
	//"1010110/1010101/1010110/1010101"",

	"1011101011010111010110",
	//"10111010110110111010110",
	"10111010110110111010",
	"10111010110101110",
	//   "1010101/1010110/1010101/1010110",
	"101101101110101101101110",
	// "1011011011101101101101110",
	// "1010110/1010110/1010101"",
	"10111010111010110",
	//   "1010110/1010110/11010",
	// "1011010/1010110/1011010/1010110",
	//  "1011010/1010110/1011010",
	//   "111010/110110/111010",
	"10110101101101010",
	"1110101101101010",
	"101101011011010",
	"11101011011010",
	"10110101101101110",
	"1110101101101110",
	// "1101010/11010/1101010",
	// "11010110101011010110110",
	//  "11010/110110/11010/110110",
	"101101010110101101010110",
	//   "1011010101101101101010110",
	"11101011101110101110",
	// "111010111011110101010",
	"11101010101110101110",
	// "111010111011110101010",
	//"101010/1110/111010/1110",
	//"111010/1110/101010/1110",
	//"111010/1110/111010/1010",
	//"1011010111010110101110",
	//"1010110/10110/1010110/10110",
	//"110110/1110/110110/1110",
	//"1101010/1101010/1011010",
	// "10101/110101/1011010",
	//"1011010/1011010/1010110",
	// "111010/111010/110110",
	//"1011010/1101010/1101010",
	"10110111010111010",
	"11011010110110101101101011011010",
	"101101101010",
	"10110110110",
	"11010101101010",
	"110110110110110110110",
	"1011010111010111010",
	"10110101011010",
	"101101010110",
	"1101011010",
	"11101101110110",
	//   "11010/1101010",
	//   "1011010/10110",
	"11010101101010110101011010101101010110101011010101101010",
	"1101101011011010",
	"110110101101101011011010",
	"110110110110110110"
};

#endif



