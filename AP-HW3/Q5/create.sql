create table users(
	id integer primary key,
    telegram_id varchar(255),
    phone varchar(20) not null,
    email varchar(255),
    password varchar(255),
    first_name varchar(255),
    last_name varchar(255),
    vertification_code varchar(255),
    profile_picture_url varchar(255),
    create_at timestamp not null,
    update_at timestamp not null
);

create table blockUser(
	blocker_user_id integer,
	blocked_user_id integer,
	ecreated_at timestamp not null,
	primary key(blocker_user_id,blocked_user_id),
	foreign key(blocker_user_id) references users(id),
	foreign key(blocked_user_id) references users(id)
);

create table Message(
	id integer primary key,
    sender_id integer,
    receiver_id integer,
    message_type varchar(20),
    message_text varchar(500),
    create_at timestamp not null,
    update_at timestamp not null,
    foreign key(sender_id) references users(id),
    foreign key(receiver_id) references users(id)

);

create table channel(

	id int primary key,
	telegram_id varchar(255) not null,
    title  varchar(255),
    info varchar(255),
    creator_id int,
    create_at timestamp,
    update_at timestamp,
    foreign key(creator_id) references users(id)
);

create table groups(
	id integer primary key,
	creator_id integer,
	title varchar(255),
	join_url varchar(255) not null,
	create_at timestamp,
	update_at timestamp,
    foreign key(creator_id) references users(id)

);

create table GroupMessage(
	id integer primary key,
	group_id integer,
	sender_id integer,
	message_type varchar(20),
	message_text varchar(500),
	create_at timestamp,
	update_at timestamp,
    foreign key(sender_id) references users(id),
    foreign key(group_id) references groups(id)

);

create table channelMessage(
	id integer primary key,
	channel_id integer,
	message_type varchar(20),
	message_text varchar(500),
	create_at timestamp,
	update_at timestamp,
    foreign key(channel_id) references channel(id)

);

create table messageAttachment(
	message_id integer primary key,
	attachment_url varchar(255),
	attachment_thumb_url varchar(255),
	foreign key (message_id) references Message(id)

);

create table GroupMessageAttachment(
	message_id integer primary key,
	attachment_url varchar(255),
	attachment_thumb_url varchar(255),
	foreign key (message_id) references GroupMessage(id)

);

create table ChannelMessageAttachment(
	message_id integer primary key,
	attachment_url varchar(255),
	attachment_thumb_url varchar(255),
	foreign key (message_id) references channelMessage(id)
);

create table ChannelMemberShip(
	user_id integer,
	channel_id integer,
	create_at timestamp,
	primary key(user_id ,channel_id),
	foreign key(user_id) references users(id),
	foreign key(channel_id) references channel(id)
);

create table GroupMemberShip(
	user_id integer,
	group_id integer,
	create_at timestamp,
	primary key(user_id,group_id),
	foreign key(user_id) references users(id),
	foreign key(group_id) references groups(id)
);


create table channel_moreThanAdmin(

	id int primary key,
	telegram_id varchar(255) not null,
    title  varchar(255),
    info varchar(255),
    creator_id int,

    admin_id int[],

    create_at timestamp,
    update_at timestamp,
    foreign key(creator_id) references users(id),
    foreign key(admin_id,id) references admin(admin_id[],channel_id) 
);

create table admin(
	channel_id int,
	admin_id int,
	primary key(channel_id,admin_id),
	foreign key(channel_id) references channel(id),
	foreign key(admin_id) references users(id)
);




















