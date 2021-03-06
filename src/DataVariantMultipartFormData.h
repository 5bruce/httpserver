﻿#pragma once

#include "DataVariantAbstract.h"

namespace HttpServer
{
	class DataVariantMultipartFormData: public DataVariantAbstract
	{
	public:
		DataVariantMultipartFormData();

	protected:
		static bool append
		(
			const SocketAdapter &sock,
			const std::chrono::milliseconds &timeout,
			std::vector<char> &buf,
			std::string &str_buf,
			const std::string &data_end,
			const size_t &leftBytes,
			long &recv_len,
			size_t &recv_total_len
		);

	public:
		virtual bool parse
		(
			const SocketAdapter &sock,
			std::string &str,
			const size_t leftBytes,
			std::unordered_map<std::string, std::string> &contentParams,
			struct request_parameters &rp
		) override;
	};
};