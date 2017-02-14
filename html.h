
#define rplc(x,y){strcpy(s[x].tag,y);s[x].size=strlen(y);}
#define nmemb 1000	//写入nmemb数目

struct tt{
	char tag[100];
	int size;
}s[nmemb];		//替换的标签

void replace(){
    rplc(1,"<!DOCTYPE HTML>");
    rplc(2,"<html>");
    rplc(3,"<head>");
    rplc(4,"<meta charset=\"utf-8\">");
    rplc(5,"<meta http-equiv=\"Content-Type\" content=\"text/html\" />");
    rplc(6,"<link href=\"CSS/test.css\" rel=\"stylesheet\" type=\"text/css\" />");
    rplc(7,"<title>task</title>");
    rplc(8,"</head>");
    rplc(9,"<body>");
	rplc(10,"<h1>");	//#
	rplc(11,"</h1>");
	rplc(12,"<h2>");	//##
	rplc(13,"</h2>");
	rplc(14,"<h3>");	//###
	rplc(15,"</h3>");
	rplc(16,"<h4>");	//####
	rplc(17,"</h4");
	rplc(18,"<h5>"); 	//#####
	rplc(19,"</h5>");
	rplc(20,"<h6>"); 	//######
	rplc(21,"</h6>");
	rplc(22,"<p>"); 	//text
	rplc(23,"</p>");
	rplc(24,"<ol>"); //有序列表 num. space
	rplc(25,"</ol>");
	rplc(26,"<li>"); //list
	rplc(27,"</li>")
	rplc(28,"<ul>"); //* space && + space && - space
	rplc(29,"</ul>");	//无序列表
	rplc(30,"<em>"); //斜体 *text* && _text_
	rplc(31,"</em>");
	rplc(32,"<strong>"); //粗体 **text** && __text__
	rplc(33,"</strong");
	rplc(34,"<img src=\" "); //img
	rplc(35,"\" />");
	rplc(36,"</body>");
	rplc(37,"</html>");
}			//	漏写表格，记得补