insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(123456,'@ali_karimi',
	'09120000001','ali@gmail.com','abc147','ali','karimi',147258,'http://picture.com',now(),now());

insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(456789,'@reza_nasiry',
	'09153615069','reza@gmail.com','edc857','reza','nasiry',521365,'http://picture.com/ff',now(),now());	


insert into blockuser(blocker_user_id,blocked_user_id,ecreated_at)values(123456,456789,now());

insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(6523,123456,456789,'text','hi
	how are you',now(),now());	

insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(36,'@news','hot news','auther:Dr.Karimi',123456,now(),now());

insert into groups(id,creator_id,title,join_url,create_at,update_at)values(24,123456,'friends','http://t.me/joinchat/c_asw',now(),now());

insert into groupMessage(id,group_id,sender_id,message_type,message_text,create_at,update_at)values(54263,24,123456,
	'text','hi every one',now(),now());	

insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(874562,36,
	'text','Iran team win',now(),now());


insert into messageAttachment(message_id,attachment_url,attachment_thumb_url )values(6523,
	'http://attach415.com/hgb','http://attach415.com/hgb/dcvfgh');

insert into GroupMessageAttachment (message_id,attachment_url,attachment_thumb_url )values(54263,
	'http://attach52.com/dxs','http://attach52.com/dxs/axdfv');


insert into ChannelMessageAttachment(message_id,attachment_url,attachment_thumb_url )values(874562,
	'http://attach99.com/stg','http://attach99.com/stg/axdfv');

insert into ChannelMemberShip(user_id,channel_id,create_at)values(456789,36,now());

insert into GroupMemberShip(user_id,group_id,create_at)values(456789,24,now());	




insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(147852,'@hamid_ghaderi',
	'09162587454','hamid@gmail.com','rfgb521','hamid','ghaderi',746932,'http://picture.com/dcv',now(),now());	

insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(14,'@fun','fun man','auther:badboy',456789,now(),now());
insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(15,'@music','iranian music','auther:Homayon',147852,now(),now());

insert into ChannelMemberShip(user_id,channel_id,create_at)values(123456,14,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(123456,15,now());

insert into ChannelMemberShip(user_id,channel_id,create_at)values(147852,36,now());


insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(65,'@aut_ap_2019',
	'advance programming','Dr.jahanshahi',123456,now(),now());

insert into ChannelMemberShip(user_id,channel_id,create_at)values(456789,65,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(147852,65,now());




insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(102030,'@sepehr_javid',
	'09353615069','sepehr@gmail.com','8wd4saa','sepehr','javid',8436951,'http://picture.com/8fd',now(),now());	

insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(405060,'@sara_nori',
	'09353525069','sara@gmail.com','522243','sara','nori',555874,'http://picture.com/47qw',now(),now());	


insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(909090,'@ghasem_basir',
	'09552154178','ghasem@gmail.com','522536','ghasem','basir',555874,'http://picture.com/47qw','2011-10-14 10:55:42','2012-08-05 10:55:42');	

insert into blockuser(blocker_user_id,blocked_user_id,ecreated_at)values(123456,909090,'2019-03-02 10:55:42');
insert into blockuser(blocker_user_id,blocked_user_id,ecreated_at)values(123456,102030,now());


insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(987654,'@rahim_rad',
	'09132568714','rahim@gmail.com','hngtndf','rahim','rad',865947,'http://picture.com/42d',now(),now());	


insert into ChannelMemberShip(user_id,channel_id,create_at)values(147852,14,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(102030,14,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(405060,14,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(987654,14,now());


insert into ChannelMemberShip(user_id,channel_id,create_at)values(147852,15,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(102030,15,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(405060,15,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(987654,15,now());


insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(369852,'@ahmad_hafezpour',
	'09350028714','ahmad@gmail.com','asd5412','ahmad','hafezpour',745291,'http://picture.com/745q',now(),now());	

insert into ChannelMemberShip(user_id,channel_id,create_at)values(369852,15,now());




insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(100200,'@amir.jahanshahi',
	'09124562020','amir@gmail.com','dcfv4178','amir','jahanshahi',786519,'http://picture.com/745de',now(),now());	

insert into users(id,telegram_id,phone,email,password,first_name,last_name,
	vertification_code,profile_picture_url,create_at ,update_at)values(200100,'@sHDiV4RHs',
	'09125552036','shadi@gmail.com','edr4521','shadi','pahlevan',745821,'http://picture.com/45fgb',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4030,100200,200100,'text','hi
	how are you',now(),now());


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4031,200100,100200,'text',
	'hi proffessor tanks',now(),now());			


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4032,100200,200100,'text',
	'what is your project',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4033,100200,200100,'text',
	'is this about machine learning',now(),now());	



insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4034,200100,100200,'text',
	'yes sir!',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4035,200100,100200,'text',
	'it is about image process',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4036,200100,100200,'text',
	'whats your question proffessor?',now(),now());	



insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4037,100200,200100,'text',
	'i wanna set class to educate machine learning',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4038,100200,200100,'text',
	'you should take apart in this class',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4039,100200,200100,'text',
	'i tell you time of class today',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4040,200100,100200,'text',
	'ok! ',now(),now());	


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4041,200100,100200,'text',
	'its very good',now(),now());

insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(4042,200100,100200,'text',
	'tanks',now(),now());			


insert into Message(id,sender_id,receiver_id ,message_type,message_text,create_at,update_at)values(5874,100200,147852,'text',
	'good afternoon my friends',now(),now());			






/////////////////////////////////////////////
/////////////////////////////////////////////
//////////////////////////////////////////////


insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(88,'@football','player'
	,'auther:football lover',456789,'2011-10-14 10:55:42','2012-08-05 10:55:42');



insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(1853645,88,
	'text','team melii wins','2018-04-05 10:55:42','2018-04-06 15:35:10');

insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(7865913,88,
	'text','Perspolic wins','2019-02-05 10:55:42','2019-02-06 15:35:10');


insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(1458888,88,
	'text','God is great','2019-03-03 10:55:42','2019-03-04 15:35:10');




insert into channel(id,telegram_id,title,info,creator_id,create_at,update_at)values(56,'@friendship','friendship'
	,'auther:lover',123456,'2011-10-14 10:55:42','2012-08-05 10:55:42');


insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(4758361,56,
	'text','this good is good','2019-02-10 10:55:42','2019-02-11 15:35:10');


insert into channelMessage(id,channel_id,message_type,message_text,create_at,update_at)values(7458912,56,
	'text','friendship is good','2019-04-10 10:55:42','2019-04-10 15:35:10');



insert into ChannelMemberShip(user_id,channel_id,create_at)values(147852,88,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(102030,88,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(405060,88,now());


insert into ChannelMemberShip(user_id,channel_id,create_at)values(200100,56,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(100200,56,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(405060,56,now());
insert into ChannelMemberShip(user_id,channel_id,create_at)values(987654,56,now());




insert into channel_moreThanAdmin(id,telegram_id,title,info,creator_id,admin_id,create_at,update_at)values(965,'@Admin','more than admin','auther:Dr.Karimi',
	123456,'{{45678},{100200}}',now(),now());


insert into group_moreThanAdmin(id,creator_id,admin_id,title,join_url,create_at,update_at)values(474
	,123456,'{{100200},{200100}}','friends','http://t.me/joinchat/c_asw',now(),now());










