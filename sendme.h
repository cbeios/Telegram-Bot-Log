#include <string>
#include <iostream>
#include <fstream>

void sendtele(const std::string& text, const std::string& chatId, const std::string& token) 
{
    NSString *urlString = 
    [NSString stringWithFormat:@"https://api.telegram.org/bot%@/sendMessage", [NSString stringWithCString:token.c_str() encoding:NSUTF8StringEncoding]]; 
    NSString *params = [NSString stringWithFormat:@"chat_id=%@&text=%@", 
    [NSString stringWithCString:chatId.c_str() encoding:NSUTF8StringEncoding], 
    [NSString stringWithCString:text.c_str() encoding:NSUTF8StringEncoding]];
    NSURL *url = [NSURL URLWithString:urlString];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"POST"];
    [request setHTTPBody:[params dataUsingEncoding:NSUTF8StringEncoding]];
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) 
    {
        if (error) 
        {
            NSLog(@"Error: %@", error.localizedDescription);
        } 
        else 
        {
            NSLog(@"Response: %@", [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]);
        }
    }];
    [task resume]; 
}
void SendLog(const std::string& text) // Send log to APIBot Telegram
{
    std::string chatId = "123456"; // ID CHAT ADMIN
    std::string token = "723454fasaADDSDSFAS2fULpdPREasdasdasA"; // Token bot  
    sendtele(text, chatId, token);
}
