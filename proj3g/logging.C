
#include <logging.h>

DataFlowException::DataFlowException(const char *type, const char *error)
{
    sprintf(msg, "%s: %s", type, error);
    Logger::LogEvent(msg);
}

FILE * Logger::logger = NULL;

void
Logger::LogEvent(const char *event)
{
    if (logger == NULL)
    {
        logger = fopen("logger", "w");
    }
    fprintf(logger, "%s\n", event);
}

void
Logger::Finalize()
{
    fclose(logger);
}
